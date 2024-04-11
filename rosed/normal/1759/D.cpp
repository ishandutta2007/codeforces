#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
void solve()
{
	int n,m;
	cin>>n>>m;
	int k=1,mm=m;
	int num2=0,num5=0;
	int x=n;
	while(x%2==0) x>>=1,++num2;
	while(x%5==0) x/=5,++num5;
	while(num2>num5&&k*5<=m) k*=5,mm/=5,++num5;
	while(num2<num5&&k*2<=m) k*=2,mm/=2,++num2;
	while(k*10<=m) k*=10,mm/=10;
	k*=mm;
	cout<<n*k<<'\n';

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}