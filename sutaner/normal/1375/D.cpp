#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 2020
using namespace std;

int n, a[maxn], num[maxn], ans[maxn << 1], cs = 0;

inline void getmex(int& mex){
	rep(i, 0, n) if (!num[i]) {mex = i; return;}
	assert(false);
}

inline void check(bool& ok){
	ok = 1;
	srep(i, 1, n) if (a[i] > a[i + 1]) {ok = 0; return;}
}
inline void update(int i, int mex){
	ans[++cs] = i;
	num[a[i]]--;
	a[i] = mex;
	num[a[i]]++; 
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", a + i), num[a[i]]++;
		bool ok = 0; int mex = 0;
		check(ok);
		while (!ok){
			getmex(mex);
			if (mex == n){
				rep(i, 1, n) if (a[i] != i - 1) {update(i, mex); break;}
			}
			else update(mex + 1, mex); 
			check(ok);
		}
		printf("%d\n", cs);
		rep(i, 1, cs) printf("%d ", ans[i]); printf("\n");
		cs = 0;
		rep(i, 0, n) num[i] = 0;
	} 
	return 0;
}