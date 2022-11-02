#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

int power(int a, int b, int m, int ans=1) {
	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
	return ans;
}

int calc(int x, int k) {
	if(x == 1) return 1;
	if(k % 2 == 1 and x == 3) return 1;
	if(k % 2 == 1 and x == 2) return 0;
	if(k % 2 == 1 and x == 4) return 2;
	if(k % 2 == 0 and x == 2) return 2;
	if(x % 2) return 0;
	if(k % 2 == 0) return 1;
	int s = calc(x/2, k);
	if(s != 1) return 1;
	return 2;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n, k;
	gn(n, k);
	
	int ans = 0;
	for(int i=1, x; i<=n; i++) gn(x), ans ^= calc(x, k);
	
	if(ans) puts("Kevin");
	else puts("Nicky");

}