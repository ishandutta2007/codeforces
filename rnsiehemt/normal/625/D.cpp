#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100005;

char ss[MaxN];
int N, n[MaxN], sum[MaxN], ans[MaxN];

int startl, startr;
void go(int l, int r, bool need, bool has) {
	if (r < l) {
		if (need != has) return;
		if (sum[N-1] == 0) return;
		bool okay = true;
		for (int l = startl, r = startr; l <= r; l++, r--) {
			if (sum[r] == 19) {
				okay = false;
				break;
			}
			ans[r] = sum[r] / 2;
			ans[l] = sum[r] - ans[r];
		}
		if (!okay) return;
		for (int i = startl; i <= startr; i++) printf("%d", ans[i]);
		printf("\n");
		exit(0);
	} else if (l == r) {
		sum[r] = n[r];
		if (has) sum[r]--;
		if (need) sum[r] += 10;
		if (sum[r] & 1) return;
		go(l+1, r-1, false, false);
	} else {
		bool nextneed = false, nexthas = false;
		int suml = n[l], sumr = n[r];
		if (need) suml += 10;
		if (has) {
			sumr--;
			if (sumr == -1) {
				sumr += 10;
				nexthas++;
			}
		}
		if (sumr % 10 != suml % 10) {
			suml--;
			if (suml == -1) return;
			nextneed = true;
		}
		if (sumr % 10 != suml % 10) return;
		if (sumr < suml) {
			if (nexthas) return;
			nexthas = true;
			sumr += 10;
		}
		if (sumr != suml) return;
		sum[r] = sumr;
		/*int ll = n[l], rr = n[r];
		sum[r] = rr;
		if (has) {
			sum[r]--;
			rr--;
			if (rr == -1) {
				rr += 10;
			}
		}
		if (need) {
			sum[r] += 10;
			nexthas = true;
		} else nexthas = false;
		if (ll == rr) nextneed = false;
		else if (ll == rr+1) nextneed = true;
		else return;*/
		go(l+1, r-1, nextneed, nexthas);
	}
}

int main()
{
	scanf(" %s", ss);
	N = strlen(ss);
	for (int i = 0; i < N; i++) n[i] = ss[i] - '0';
	startl = 0; startr = N-1;
	go(0, N-1, false, false);
	startl = 1; startr = N-1;
	if (N >= 2 && n[0] == 1) go(1, N-1, true, false);
	printf("0\n");
}