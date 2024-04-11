#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const unsigned int p=998244353;
ull qpow(ull x,int y){ull r=1;while (y){if (y&1) r=r*x%p;x=x*x%p;y>>=1;}return r;}
const int N=1.1e6;
map<int,int> c[N];
int a[N][2],b[N][2],flg[2];
int n,m,q,i,x,y,z,cnt[2],cntt[2];
ull r;
void erase(int x,int y)
{
	int z=x+y+c[x][y]&1;
	--flg[z];
	if (!--a[x][z])
	{
		if (a[x][z^1]) --cnt[0]; else ++cntt[0];
	}
	if (!--b[y][z])
	{
		if (b[y][z^1]) --cnt[1]; else ++cntt[1];
	}
	c[x].erase(y);
}
void insert(int x,int y,int z)
{
	c[x][y]=z;
	z=z+x+y&1;
	++flg[z];
	if (!a[x][z]++)
	{
		if (a[x][z^1]) ++cnt[0]; else --cntt[0];
	}
	if (!b[y][z]++)
	{
		if (b[y][z^1]) ++cnt[1]; else --cntt[1];
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>q;cntt[0]=n;cntt[1]=m;
	while (q--)
	{
		cin>>x>>y>>z;
		if (c[x].find(y)!=c[x].end()) erase(x,y);
		if (z>=0) insert(x,y,z);
		if (cnt[0]&&cnt[1]) cout<<"0\n"; else
		{
			int ans=((cnt[0]?0:qpow(2,cntt[0]))+(cnt[1]?0:qpow(2,cntt[1]))+p-(flg[0]==0)-(flg[1]==0))%p;
			cout<<ans<<'\n';
		}
	}
}