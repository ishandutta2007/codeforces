#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N=310000;
int p[N],c[N];
char s[4];
int n;
int d[N];
int t;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&p[i]);
		scanf("%s",s+1);
		if(s[1]=='B')c[i]=0;
		if(s[1]=='R')c[i]=1;
		if(s[1]=='G')c[i]=2;
	}
	LL ans=0;
	int gt=-1;
	rep(i,1,n)if(c[i]==2){
		if(gt==-1){
			gt=i;
			t=0;
			rep(j,1,i-1)if(c[j]==0)d[++t]=p[j];
			if(t!=0)ans+=(p[i]-d[1]);
			t=0;
			rep(j,1,i-1)if(c[j]==1)d[++t]=p[j];
			if(t!=0)ans+=(p[i]-d[1]);
		}
		else{
			LL w=1ll<<50;
			//link
			LL se=p[i]-p[gt];

			t=0;
			rep(j,gt+1,i-1)if(c[j]==0)d[++t]=p[j];
			if(t!=0){
				int sb=max(p[i]-d[t],d[1]-p[gt]);
				rep(j,1,t-1)sb=max(sb,d[j+1]-d[j]);
				se+=p[i]-p[gt]-sb;
			}

			t=0;
			rep(j,gt+1,i-1)if(c[j]==1)d[++t]=p[j];
			if(t!=0){
				int sb=max(p[i]-d[t],d[1]-p[gt]);
				rep(j,1,t-1)sb=max(sb,d[j+1]-d[j]);
				se+=p[i]-p[gt]-sb;
			}
			w=min(w,se);
			//not link
			int ss=0;
			rep(j,gt+1,i-1)if(c[j]==0)ss|=1;
			else if(c[j]==1)ss|=2;
			if(ss==3){
				LL sum=0;
				rep(j,gt+1,i-1)if(c[j]==0){
					sum+=p[i]-p[gt];
					break;
				}
				rep(j,gt+1,i-1)if(c[j]==1){
					sum+=p[i]-p[gt];
					break;
				}
				w=min(w,sum);
			}
			ans+=w;
			gt=i;
		}
	}
	if(gt!=-1){
		per(i,n,gt+1)if(c[i]==0){
			ans+=p[i]-p[gt];
			break;
		}
		per(i,n,gt+1)if(c[i]==1){
			ans+=p[i]-p[gt];
			break;
		}
	}
	else{
		ans=0;
		t=0;
		rep(i,1,n)if(c[i]==0)d[++t]=p[i];
		if(t)ans+=d[t]-d[1];
		t=0;
		rep(i,1,n)if(c[i]==1)d[++t]=p[i];
		if(t)ans+=d[t]-d[1];
	}
	printf("%lld\n",ans);
	return 0;
}