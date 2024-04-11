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
const int P=1000000007;
const int N=1010000;
int fail[N];
int go[N][26],len[N],diff[N],anc[N],lst;
int n;char str[N];
int p;
int s[N];
int f[N],g[N];
void addChar(int c,int ww){
	int x=lst;
	while(s[ww]!=s[ww-len[x]-1]){
		x=fail[x];
	}
	if(!go[x][c]){
		len[p]=len[x]+2;
		int k=fail[x];
		while(s[ww]!=s[ww-len[k]-1])k=fail[k];
		fail[p]=go[k][c];


		go[x][c]=p;
		diff[p]=len[p]-len[fail[p]];
		if(diff[p]==diff[fail[p]])anc[p]=anc[fail[p]];
		else anc[p]=fail[p];
		p++;
	}
	lst=go[x][c];
}
void init(){
	p=2;
	len[0]=0;
	len[1]=-1;
	fail[0]=1;
	fail[1]=0;
	f[0]=1;
	lst=1;
}
int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	if(n&1){
		printf("0\n");
		return 0;
	}
	rep(i,1,n/2){
		s[i*2-1]=str[i]-'a';
		s[i*2]=str[n+1-i]-'a';
	}
	s[0]=-1;
	init();
	//rep(i,1,n)printf("%d",s[i]);puts("");
	rep(i,1,n){
		addChar(s[i],i);
		for(int x=lst;x;x=anc[x]){
			g[x]=f[i-(len[anc[x]]+diff[x])];
			if(anc[x]!=fail[x]){
				g[x]=(g[x]+g[fail[x]])%P;
			}
			if(i%2==0)f[i]=(f[i]+g[x])%P;
		}
	}
	printf("%d\n",f[n]);
	return 0;
}