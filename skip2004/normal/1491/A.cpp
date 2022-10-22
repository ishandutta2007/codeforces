#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
const int N = 100005;
int n, q, c;
int a[N];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> q;
	rep(i, 1, n) {
		cin >> a[i], c += a[i];
	}
	rep(i, 1, q) {
		int t, x;
		cin >> t >> x;
		if(t==1){
			c-=a[x],a[x]=!a[x],c+=a[x];
		}else{
			cout<<(x<=c?1:0)<<'\n';
		}
	}
}