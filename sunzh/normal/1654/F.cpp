#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n;
char str[1<<18|5];
int x[1<<18|5],y[1<<18|5];
int sa[1<<18|5];
int c[1<<18|5];
int main(){
	n=read();scanf("%s",str);
	for(int i=0;i<(1<<n);++i){
		x[i]=str[i]-'a';
		// printf("%d ",x[i]);
		++c[x[i]];
	}
	for(int i=1;i<26;++i) c[i]+=c[i-1];
	for(int i=0;i<(1<<n);++i) sa[--c[x[i]]]=i;
	x[sa[0]]=0;
	for(int i=1;i<(1<<n);++i){
		if(str[sa[i]]==str[sa[i-1]]) x[sa[i]]=x[sa[i-1]];else x[sa[i]]=x[sa[i-1]]+1;
	}
	for(int k=1;k<(1<<n);k<<=1){
		for(int i=0;i<(1<<n);++i) y[i]=sa[i]^k;
		memset(c,0,sizeof(c));
		for(int i=0;i<(1<<n);++i) c[x[i]]++;
		for(int i=1;i<(1<<n);++i) c[i]+=c[i-1];
		for(int i=(1<<n)-1;i>=0;--i) sa[--c[x[y[i]]]]=y[i];
		// memset(x,0,sizeof(x));
		swap(x,y);
		x[sa[0]]=0;
		for(int i=1;i<(1<<n);++i){
			if(y[sa[i]]==y[sa[i-1]]&&y[sa[i]^k]==y[sa[i-1]^k]) x[sa[i]]=x[sa[i-1]];else x[sa[i]]=x[sa[i-1]]+1;
		}
	}
	for(int i=0;i<(1<<n);++i) putchar(str[i^sa[0]]);
}