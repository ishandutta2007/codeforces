#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int,int> pir;

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

const int N = 1e6+5;

int n,m,k;
char s[N],t1[N],t2[N];
pir ans;
bool pd;
int nxt1[N],nxt2[N];
int d1[N],d2[N];
int lef[N],rig[N];
int key2[N],key1[N];

void getkey1(int x,int v){
	key1[x]=v;
	for(int y=lef[x];y;y=rig[y])
	if (!key1[y])getkey1(y,v);
}

void solve(){
	int pw=-1;
	fo(i,1,n)
	if (d1[i]==m){
		pd=1;
		pw=i;break;
	}
	if (pd){
		pw=max(1,pw-2*k+1);
		ans=make_pair(pw,pw+k);
		return;
	}
	fo(i,1,m){
		rig[i]=lef[nxt1[i]];
		lef[nxt1[i]]=i;
	}
	fd(i,n-k,k){
		int x=i+1;
		int u=d2[x];
		for(;!key2[u];u=nxt2[u]){
			key2[u]=x;
			getkey1(m-u,x);
		}
		u=d1[i];
		if (key1[u]){
			pd=1;
			ans=make_pair(i-k+1,key1[u]);
			return;
		}
	}
}

int main(){
	n=get();m=get();k=get();
	scanf("%s",s+1);
	scanf("%s",t1+1);
	fo(j,1,m)t2[j]=t1[m-j+1];
	int w=0;
	fo(i,2,m){
		while(w&&t1[w+1]!=t1[i])w=nxt1[w];
		if (t1[w+1]==t1[i])w++;
		nxt1[i]=w;
	}
	w=0;
	fo(i,2,m){
		while(w&&t2[w+1]!=t2[i])w=nxt2[w];
		if (t2[w+1]==t2[i])w++;
		nxt2[i]=w;
	}
	w=0;
	fo(i,1,n){
		while(w&&t1[w+1]!=s[i])w=nxt1[w];
		if (t1[w+1]==s[i])w++;
		while(w>k)w=nxt1[w];
		d1[i]=w;
	}
	w=0;
	fd(i,n,1){
		while(w&&t2[w+1]!=s[i])w=nxt2[w];
		if (t2[w+1]==s[i])w++;
		while(w>k)w=nxt2[w];
		d2[i]=w;
	}
	pd=0;
	solve();
	if (pd)printf("Yes\n%d %d\n",ans.first,ans.second);
	else printf("No\n");
	return 0;
}