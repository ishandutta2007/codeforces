#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n, M, T;
int s[20010];
int num[20010];

deque<int> deq;
int now;
bool ok;

int main() {
	scanf("%d %d %d", &n, &M, &T);

	rep(i, n) {
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		--hh; --mm; --ss;
		s[i] = hh * 3600 + mm * 60 + ss;

		while (deq.size() > 0 && s[deq[0]] + T <= s[i]) {
			deq.pop_front();
		}

		if (deq.size() < M) {
			num[i] = now++;
		} else {
			num[i] = num[deq.back()];
			deq.pop_back();
		}

		deq.push_back(i);
		if (deq.size() == M) ok = 1;
	}

	if (!ok) {
		puts("No solution");
	} else {
		printf("%d\n", now);
		rep(i, n) printf("%d\n", num[i] + 1);
	}

	return 0;

}