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
const int N=110000;
char s[N],t[N];
int n,m;
int Q;
int s0[N],s1[N],t0[N],t1[N];
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%s",t+1);m=strlen(t+1);
	rep(i,1,n){
		s0[i]=(s0[i-1]+(s[i]!='A'));
		s1[i]=s1[i-1]+1;
		if(s[i]!='A')s1[i]=0;
	}
	rep(i,1,m){
		t0[i]=(t0[i-1]+(t[i]!='A'));
		t1[i]=t1[i-1]+1;
		if(t[i]!='A')t1[i]=0;
	}
	scanf("%d",&Q);
	while(Q--){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int ns=s0[r1]-s0[l1-1];
		int nt=t0[r2]-t0[l2-1];
		int es=min(s1[r1],r1-l1+1);
		int et=min(t1[r2],r2-l2+1);
		//printf("%d %d %d %d",ns,nt,es,et);
		if(!ns&&nt){
			if(!(es>et)){
				putchar('0');
				continue;
			}
		}
		if(ns>nt)putchar('0');
		else if(ns==nt){
			if(es>=et&&(es-et)%3==0)putchar('1');
			else putchar('0');
		}
		else{
			if((nt-ns)%2==0&&es>=et)putchar('1');
			else putchar('0');
		}
	}
	puts("");
	return 0;
}