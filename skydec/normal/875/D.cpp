#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=210000;
int a[N],n;
int cl[N],cr[N];
int b[35];
int sl[N],sr[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);

	rep(i,1,n){
		rep(j,0,30)if(a[i]&(1<<j))b[j]=i;
		else cl[i]=max(cl[i],b[j]);
	}
	memset(b,0,sizeof b);
	per(i,n,1){
		cr[i]=n+1;
		rep(j,0,30)if(a[i]&(1<<j))b[j]=i;
		else if(b[j])cr[i]=min(cr[i],b[j]);
	}
	rep(i,2,n){
		int x=i-1;
		while(x&&a[x]<a[i])x=sl[x];
		sl[i]=x;
	}
	sr[n+1]=n+1;
	per(i,n,1){
		int x=i+1;
		while(x!=n+1&&a[x]<=a[i])x=sr[x];
		sr[i]=x;
	}
	LL ans=0;
	rep(i,1,n){
		int L=max(sl[i]+1,cl[i]+1);
		int R=min(sr[i]-1,cr[i]-1);
		ans+=(R-i+1)*1ll*(i-L+1);
	}
	cout<<n*1ll*(n+1)/2-ans<<endl;
	return 0;
}