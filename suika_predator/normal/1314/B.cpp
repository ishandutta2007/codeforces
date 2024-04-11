#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,k;
int ok[133333],cnt[133333];
pair<int,int> solve(int l,int r)//return pair(ans0,ans1)
{
	if(l+1==r)
	{
		if(ok[l]&&ok[r])return make_pair(-inf,1);
		else if(ok[l]||ok[r])return make_pair(1,1);
		else return make_pair(0,-inf);
	}
	int mid=(l+r)/2;
	auto L=solve(l,mid),R=solve(mid+1,r);
	int ans0=-inf,ans1=-inf;
	//1,1
	int tmp=L.second+R.second,ex=(cnt[mid]-cnt[l-1]>=2||cnt[r]-cnt[mid]>=2);
	ans1=max(ans1,tmp+2+ex);
	//0,1
	tmp=L.first+R.second;ex=(cnt[mid]-cnt[l-1]>=1||cnt[r]-cnt[mid]>=2);
	ans1=max(ans1,tmp+1+ex*2);
	ans0=max(ans0,tmp+2+ex);
	//1,0
	tmp=L.second+R.first;ex=(cnt[mid]-cnt[l-1]>=2||cnt[r]-cnt[mid]>=1);
	ans1=max(ans1,tmp+1+ex*2);
	ans0=max(ans0,tmp+2+ex);
	//0,0
	tmp=L.first+R.first;ex=(cnt[mid]-cnt[l-1]>=1||cnt[r]-cnt[mid]>=1);
	ans0=max(ans0,tmp+2*ex);
	return make_pair(ans0,ans1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;n=1<<n;
	if(k==0)return puts("0"),0;
	int x;
	for(int i=1;i<=k;i++)
	{
		cin>>x;
		ok[x]=1;
	}
	for(int i=1;i<=n;i++)cnt[i]=cnt[i-1]+ok[i];
	auto _=solve(1,n);
	cout<<max(_.first,_.second)+1<<endl;
	return 0;
}