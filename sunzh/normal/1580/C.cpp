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
int n,m;
struct node{
	int x,y;
}a[200010];
int in[200010];
int B=450;
int val[400010];
int vl2[510][510];
void ins(int x,int tm){
	in[x]=tm;
	int all=a[x].x+a[x].y;
	if(all<=B){
		int beg=tm%all;
		for(int j=0;j<a[x].y;++j){
			vl2[all][(j+beg+a[x].x)%all]++;
		}
	}
	else{
		int nt=in[x];
		while(nt<=m){
			if(nt+a[x].x<=m) ++val[nt+a[x].x];
			
			if(nt+a[x].x+a[x].y<=m) --val[nt+a[x].x+a[x].y];
			nt+=all;
		}
	}
}
int su;
void del(int x,int tm){
	int all=a[x].x+a[x].y;
	if(all<=B){
		int beg=in[x]%all;
		for(int j=0;j<a[x].y;++j){
			vl2[all][(j+beg+a[x].x)%all]--;
		}
	}
	else{
		int nt=in[x];
		while(nt<=m){
			if(tm>=nt+a[x].x) --su;
			if(tm>=nt+a[x].x+a[x].y) ++su;
			if(nt+a[x].x<=m) --val[nt+a[x].x];
			
			if(nt+a[x].x+a[x].y<=m) ++val[nt+a[x].x+a[x].y];
			nt+=all;
		}
	}
}
int getans(int tm){
	int res=0;
	for(int i=1;i<=B;++i){
		res+=vl2[i][tm%i];
	}
	return res;
}
int main(){
	su=0;
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i].x=read(),a[i].y=read();
	for(int i=1;i<=m;++i){
		int op=read(),k=read();
		su+=val[i];
		if(op==1){
			ins(k,i);
		}
		else del(k,i);
		printf("%d\n",su+getans(i));
	}
}