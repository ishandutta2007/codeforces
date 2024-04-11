#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define em emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 2005;

int N, M, bestk;
ll a[MaxN], b[MaxN], sa, sb, bestv;
std::pair<int, int> swap[2];
std::vector<std::pair<ll, std::pair<int, int>>> apair, bpair;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", a+i);
		sa += a[i];
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%lld", b+i);
		sb += b[i];
	}

	bestv = std::abs(sa - sb);
	bestk = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (domin(bestv, std::abs((sa - a[i] + b[j]) - (sb + a[i] - b[j])))) {
				bestk = 1;
				swap[0] = {i, j};
			}
		}
	}

	for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) apair.pb({a[i] + a[j], {i, j}});
	std::sort(all(apair));
	for (int i = 0; i < M; i++) for (int j = i+1; j < M; j++) bpair.pb({b[i] + b[j], {i, j}});
	std::sort(all(bpair));

	int j = 0;
	for (int i = 0; i < sz(apair); i++) {
		ll newsa = sa - apair[i].first*2;
		while (j < sz(bpair)) {
			ll newsb = sb - bpair[j].first*2;
			if (domin(bestv, std::abs(newsa - newsb))) {
				bestk = 2;
				swap[0] = {apair[i].second.first, bpair[j].second.first};
				swap[1] = {apair[i].second.second, bpair[j].second.second};
			}
			if (newsb <= newsa) break;
			else j++;
		}
	}

	printf("%lld\n%d\n", bestv, bestk);
	for (int k = 0; k < bestk; k++) printf("%d %d\n", swap[k].first + 1, swap[k].second + 1);
}