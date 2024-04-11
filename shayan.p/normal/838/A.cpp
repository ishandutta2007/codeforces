#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=3000;
ll pre[maxn][maxn],n,m,Ans,Num_Ans;
bool a[maxn][maxn];
ll pos(ll k)
{
	ll ans=0;
	for(ll i=1;i<=((n%k)?(n/k)+1:n/k);i++)
		for(ll j=1;j<=((m%k)?(m/k)+1:m/k);j++) // i and j end points
		{
			ll I=k*i,J=k*j;
			ll num=pre[min(I,n)][min(J,m)]-pre[min(I-k,n)][min(J,m)]-pre[min(I,n)][min(J-k,m)]+pre[min(I-k,n)][min(J-k,m)];
			ans+=min(num,(k*k)-num);
		}
		return ans;
}
int main()
{
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		string s;cin>>s;
		for(ll j=1;j<=m;j++)
		{
			a[i][j]=(s[j-1]=='1');
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j];
		}
	}
	Ans=pos(2);
	for(ll i=3;i<=n;i++)Ans=min(Ans,pos(i));
	cout<<Ans;
}