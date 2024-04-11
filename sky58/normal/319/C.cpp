#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint inf=1e18;
lint a[100010],b[100010],dp[100010];
lint cal(int i,int j){return dp[j]+b[j]*a[i];}
void cal2(int l1,int h1,int l2,int h2){
	if(l1>=h1) return;
	int mi=(l1+h1)/2,it=l2;
	REP(i,l2,h2){
		if(cal(mi,i)<cal(mi,it)) it=i;
	}
	dp[mi]=min(dp[mi],cal(mi,it));
	cal2(l1,mi,l2,it+1);
	cal2(mi+1,h1,it,h2);
}
void rec(int lo,int hi){
	if(lo+2>hi) return;
	int mi=(lo+hi)/2;
	rec(lo,mi);
	cal2(mi,hi,lo,mi);
	rec(mi,hi);
}
int main()
{
	int s=0,t=1,n;
	cin>>n;
	rep(i,n) scanf("%I64d",&a[i]);
	rep(i,n) scanf("%I64d",&b[i]);
	dp[0]=0;
	REP(i,1,n+10) dp[i]=inf;
	rec(0,n);
	cout<<dp[n-1]<<endl;
}