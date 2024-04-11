#include<bits/stdc++.h>
using namespace std;
int a[333333],zero;
int n,q,MOD,x;
void mod(int pos,int del)
{
	if(del==0)return;
	//2~n+1
	if(pos<=n+1)
	{
		if(a[pos]==0)zero--;
	}
	a[pos]=(a[pos]+del)%MOD;
	if(pos<=n+1)
	{
		if(a[pos]==0)zero++;
	}
}
void add(int pos,int del)
{
	pos++;
	mod(pos,del);
	mod(pos+1,(MOD-del)%MOD);
	mod(pos+2,(MOD-del)%MOD);
}
int f[333333];
void addr(int l,int r,int del)
{
	l++,r++;
	mod(l,del);
	mod(r+1,1ll*(f[r-l+1]+f[r-l])*(MOD-del)%MOD);
	mod(r+2,1ll*f[r-l+1]*(MOD-del)%MOD);
}
int ok;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q>>MOD;
	f[1]=f[2]=1%MOD;
	for(int i=3;i<=n+5;i++)f[i]=(f[i-1]+f[i-2])%MOD;
	zero=n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		add(i,x);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		add(i,(MOD-x)%MOD);
	}
//		for(int i=2;i<=n+3;i++)cerr<<a[i]<<' ';cerr<<endl;
	while(q--)
	{
		string ty;
		int l,r;
		cin>>ty>>l>>r;
		if(ty=="A")
		{
			if(l==r)add(l,(1)%MOD);
			else addr(l,r,(1)%MOD);
		}
		else
		{
			if(l==r)add(l,(MOD-1)%MOD);
			else addr(l,r,(MOD-1)%MOD);
		}
		if(zero==n)cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
//		for(int i=2;i<=n+3;i++)cerr<<a[i]<<' ';cerr<<endl;
	}
	return 0;
}