#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
const int N = 100005;
int t, n, u, v;
int a[N];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	rep(i, 1, t) {
		cin >> n >> u >> v;
		int qaq=1;
		rep(i, 1, n) cin >> a[i];
		rep(i, 2, n) qaq &= std::abs(a[i] - a[i - 1]) < 2;
		if(!qaq){
			cout<<0<<'\n';
		}else{
			int dif=0;
			rep(i, 2, n) if(a[i]!=a[i-1])dif=1;
			if(dif){
				cout<<std::min(u,v)<<'\n';
			}else{
				cout<<v+std::min(u,v)<<'\n';
			}
		}
	}
}