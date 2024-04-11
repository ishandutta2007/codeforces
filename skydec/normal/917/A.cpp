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
const int N=5005;
int n;char s[N];
int num[N];
int sum[N];
int idx[N];
int mi[N][N];
int ok[N][N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,1,n){
		num[i]=(num[i-1]+(s[i]=='?'));
		if(s[i]=='?')idx[num[i]]=i;
	}
	rep(i,1,n){
		sum[i]=sum[i-1];
		if(s[i]=='(')sum[i]++;
		if(s[i]==')')sum[i]--;
	}
	rep(i,1,n){
		int now=0;
		int gg=0;
		rep(j,i,n){
			if(s[j]=='?'||s[j]==')')--now;
			else ++now;
			gg=min(gg,now);
			mi[i][j]=gg;
		}
	}
	rep(i,1,n){
		int now=0;
		rep(j,i,n){
			if(s[j]=='('||s[j]=='?')++now;
			else --now;
			if(now<0)break;
			ok[i][j]=1;
		}
	}

	int ans=0;
	rep(i,1,n)rep(j,i,n)if((j-i+1)%2==0){
		int wen=num[j]-num[i-1];
		int sb=sum[j]-sum[i-1];

		if(!wen){
			if(sb==0&&ok[i][j])++ans;
			continue;
		}

		if(abs(sb)>wen)continue;

		int lf=0;

		if(sb>0)lf=wen-((wen-abs(sb))/2+abs(sb));
		else lf=abs(sb)+((wen-abs(sb))/2);

		int d;
		if(lf)
		d=idx[num[i-1]+lf];
		else d=idx[num[i-1]+lf+1]-1;
		//printf("%d %d %d %d\n",i,j,d,lf);
		//[i,d],[d+1,j]
		if(!ok[i][d])continue;

		int pr=sum[d]-sum[i-1]+num[d]-num[i-1];
		if(mi[d+1][j]+pr<0)continue;
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}