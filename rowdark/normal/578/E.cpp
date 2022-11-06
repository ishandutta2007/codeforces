#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stack>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
stack<int> S[2];//0 -> L 1 -> R x -> pos
char s[100100];

int pre[100100];
int nxt[100100];

int n,ans;

vector<int> cnt[2][2];


void swapRelation(int x,int y){
	swap(pre[x],pre[y]);
	if(pre[x]!=-1){
		nxt[pre[x]]=x;
	}
	if(pre[y]!=-1){
		nxt[pre[y]]=y;
	}
}

void modify(int &x,int &y){
	int nx=x,ny=y;
	while(nxt[nx]!=-1&&nxt[nx]<y) nx=nxt[nx];
	while(nxt[ny]!=-1&&nxt[ny]<x) ny=nxt[ny];
	if(nx<y){
		if(s[nx]==s[ny]){
			y=nx;
			swapRelation(nx,ny);
		}
		else{
			y=nxt[nx];
			swapRelation(nxt[nx],ny);
		}
	}
	else{
		if(s[nx]==s[ny]){
			x=ny;
			swapRelation(nx,ny);
		}
		else{
			x=nxt[ny];
			swapRelation(nx,nxt[ny]);
		}
	}
}

inline int ch(char c){
	return c=='R';
}

int anss[100100],anscnt;

void pushall(const vector<int> &V){
	for(int i=0;i<(int)V.size();++i){
		int x=V[i];
		while(x!=-1){
			anss[++anscnt]=x;
			x=nxt[x];
		}
	}
}

int checkanss(){
	int ret=0;
	for(int i=1;i<n;++i){
		if(s[anss[i]]==s[anss[i+1]]) return -1;
		ret+=anss[i]>anss[i+1];
	}
	return ret;
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(nxt,-1,sizeof(nxt));
	memset(pre,-1,sizeof(pre));
	for(int i=1;i<=n;++i){
		int v=s[i]=='R';
		if(S[v].empty()){
			++ans;
		}
		else{
			int x=S[v].top();
			S[v].pop();
			nxt[x]=i;
			pre[i]=x;
		}
		S[!v].push(i);
	}
	for(int i=1;i<=n;++i) if(pre[i]==-1){
		int y=i;
		while(nxt[y]!=-1) y=nxt[y];
		cnt[ch(s[i])][ch(s[y])].push_back(i);
	}
	if(ans==1){
		printf("0\n");
		for(int i=1;i<=n;++i){
			printf("%d%c",i,i==n?'\n':' ');
		}
		return 0;
	}
	while((int)cnt[0][0].size()>1&&(int)cnt[1][1].size()>1){
		int a=cnt[0][0].back();
		int b=cnt[1][1].back();
		cnt[0][0].pop_back();
		cnt[1][1].pop_back();
		modify(a,b);
		cnt[0][1].push_back(a);
		cnt[1][0].push_back(b);
	}
	if(!(int)cnt[0][0].size()&&!(int)cnt[1][1].size()){
		if((int)cnt[0][1].size()&&(int)cnt[1][0].size()){
			int a=cnt[0][1].back();
			int b=cnt[1][0].back();
			cnt[0][1].pop_back();
			cnt[1][0].pop_back();
			modify(a,b);
			cnt[0][0].push_back(a);
			cnt[1][1].push_back(b);
		}
	}
	printf("%d\n",ans-1);
	if(cnt[0][0].size()){//01 00 10 11
		pushall(cnt[0][1]);
		pushall(cnt[0][0]);
		pushall(cnt[1][0]);
		pushall(cnt[1][1]);
	}
	else{
		pushall(cnt[1][0]);
		pushall(cnt[1][1]);
		pushall(cnt[0][1]);
		pushall(cnt[0][0]);
	}
	for(int i=1;i<=n;++i){
		printf("%d%c",anss[i],i==n?'\n':' ');
	}
	assert(checkanss()==ans-1);
	return 0;
}