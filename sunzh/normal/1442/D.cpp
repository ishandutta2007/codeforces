#pragma GCC optimize(2)
#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,k;
vector<int>a[3010];
int Ans;
void solve(int l,int r,vector<int>F){
	if(l==r){
		int len=a[l].size();
		for(int i=0;i<len;++i){
			Ans=max(Ans,F[k-i]+a[l][i]);
		}
		return ;
	}
	vector<int>res;res.resize(k+2);
	for(int i=0;i<=k;++i) res[i]=F[i];
	int mid=l+r>>1;
	for(int i=l;i<=mid;++i){
		int len=a[i].size()-1;
		for(int j=k;j>=len;--j){
			res[j]=max(res[j],res[j-len]+a[i][len]);
		}
	}
	solve(mid+1,r,res);
	vector<int>res2;res2.resize(k+2);
	for(int i=0;i<=k;++i) res2[i]=F[i];
	for(int i=mid+1;i<=r;++i){
		int len=a[i].size()-1;
		for(int j=k;j>=len;--j) res2[j]=max(res2[j],res2[j-len]+a[i][len]);
	}
	solve(l,mid,res2);
}
signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		int t=read();
		a[i].pb(0);
		int sum=0;
		for(int j=1;j<=t;++j){
			int x=read();
			if(j<=k){
				sum+=x;a[i].pb(sum);
			}
		}
	} 
	vector<int>emp;
	emp.pb(0);for(int i=1;i<=k;++i) emp.pb(-0x3f3f3f3f);
	solve(1,n,emp);
	printf("%lld\n",Ans);
}