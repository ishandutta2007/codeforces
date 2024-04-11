#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=50000;
ll n,m,k,a[N],b[N],dp[N],c[N],jj[N],j2[N],ans;
int main(){
	cin>>n>>m>>k;
	f(i,0,n) cin>>a[i];
	f(i,0,m) cin>>b[i];
	if(a[0]==1) dp[0]=1,jj[1]++;
	f(i,1,n){
		if(a[i]==1) dp[i]=dp[i-1]+1;
		jj[dp[i]]++;
	}
	if(b[0]==1) c[0]=1,j2[1]++;
	f(i,1,m){
		if(b[i]==1) c[i]=c[i-1]+1;
		j2[c[i]]++;
	}
	f_(i,max(n,m),1){
		jj[i]+=jj[i+1];
		j2[i]+=j2[i+1];
	}
	for(int i=1;i*i<=k;i++){
		if(k%i==0){
			if(i<=n && k/i<=m)
				ans+=jj[i]*j2[k/i];
		}
		if(k%i==0 && i*i!=k){
			if(i<=m && k/i<=n) ans+=j2[i]*jj[k/i];
		}
	}
	cout<<ans;
	
}