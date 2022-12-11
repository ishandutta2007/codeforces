#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
	
using namespace std;

typedef double db;
typedef long long LL;
typedef unsigned long long ull;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 2e5+5;
const int L = 5.1e6;
const LL P = 887837549;

int n,q;
int a[N];
int pri[L],k,lst[L+5];

void prepare(){
	fo(i,2,L){
		if (!lst[i]){
			lst[i]=i;
			pri[++k]=i;
		}
		fo(j,1,k){
			if (1ll*pri[j]*i>L)break;
			lst[i*pri[j]]=pri[j];
			if (i%pri[j]==0)break;
		}
	}
}

int key[N][20];
int d[100];
int m;
map<ull,int>id;

const int MAXN =  1.28e7;

struct node{
	int v,w,nxt;
}e[MAXN];
int h[MAXN],tot;

void inse(int x,int v,int w){e[++tot].v=v;e[tot].w=w;e[tot].nxt=h[x];h[x]=tot;}

int main(){
	prepare();
	n=get();q=get();
	fo(i,0,15)key[0][i]=-1;
	k=0;
	fo(i,1,n){
		a[i]=get();
		fo(c,0,15)key[i][c]=key[i-1][c];
		int x=a[i];
		m=0;
		for(;x>1;){
			int tim=0,v=lst[x];
			while(x%v==0){
				tim^=1;
				x/=v;
			}
			if (tim)d[++m]=v;
		}
		fo(t,0,(1<<m)-1){
			ull v=0;
			int cnt=0;
			fo(x,1,m)
			if ((t&(1<<(x-1)))>0){
				cnt++;
				v=v*P+d[x];
			}
			if (!id[v])id[v]=++k;
			int now=id[v];
			bool in=0;
			for(int p=h[now];p;p=e[p].nxt){
				int nd=e[p].v+m-cnt*2;
				key[i][nd]=max(key[i][nd],e[p].w);
				if (e[p].v==m){
					in=1;
					e[p].w=i;
				}
			}
			if (!in)inse(now,m,i);
		}
		fo(c,1,15)key[i][c]=max(key[i][c],key[i][c-1]);
	}
	fo(cas,1,q){
		int l=get(),r=get();
		int ans=15;
		fo(i,0,15)if (key[r][i]>=l)ans=min(ans,i);
		printf("%d\n",ans);
	}
	return 0;
}