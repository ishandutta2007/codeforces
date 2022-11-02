#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back
#define ep 1e-8

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
int power(int a, int b, int m, int ans=1){for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m; return ans;}

int u,v;
int n,d;
int m;
double calc(int x1, int y1, int x2, int y2) {
	return (u-x1) * (y2 - y1)/(double)(x2 - x1)  -v + y1;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	cin>>n>>d;
	cin>>m;
	for (int i=0; i<m; i++) {
		cin>>u>>v;
		if ( calc (d,0,0,d) * calc(n,n-d, n-d,n)<=0 && calc(0,d,n-d,n) * calc(d,0,n,n-d)<=0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}