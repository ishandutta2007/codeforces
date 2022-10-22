#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector> 
#include<cstring>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n,q;
int trans[300010][30],fail[300010];
char s[300010];
VI pth[300010],vec[300010];
VII Q[300010];
int ans[500010];
int tin[300010],tout[300010];
int dfn,cnt;
void build(int x){
	int p=0,len=strlen(s+1);
	for(int i=1;i<=len;++i){
		if(!trans[p][s[i]-'a']) trans[p][s[i]-'a']=++cnt;
		p=trans[p][s[i]-'a'];
		pth[x][i-1]=p;
	}
}
int que[300010];
void getfail(){
	int head=1,tail=0;
	for(int i=0;i<26;++i) if(trans[0][i]) que[++tail]=trans[0][i];
	while(head<=tail){
		int u=que[head++];
		for(int i=0;i<26;++i){
			if(trans[u][i]){
				fail[trans[u][i]]=trans[fail[u]][i];
				que[++tail]=trans[u][i];
			}
			else trans[u][i]=trans[fail[u]][i];
		}
	}
	for(int i=1;i<=cnt;++i) vec[fail[i]].pb(i);
}
void dfs(int x){
	tin[x]=++dfn;
	for(auto i:vec[x]){
		if(i!=fail[x]) dfs(i);
	}
	tout[x]=dfn;
}
int tre[500010];
inline void update(int x,int k){
	while(x<=dfn){
		tre[x]+=k;
		x+=x&-x;
	}
}
inline int query(int x){
	int res=0;
	while(x){
		res+=tre[x];
		x&=x-1;
	}
	return res;
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		pth[i].resize(strlen(s+1)); 
		build(i);
	}
//	printf("cnt:%d\n",cnt);fflush(stdout);
	getfail();
	dfs(0);
	for(int i=1;i<=q;++i){
		int l=read(),r=read(),k=read();
		Q[l-1].pb(mp(pth[k].back(),-i));Q[r].pb(mp(pth[k].back(),i));
	}
	for(int i=1;i<=n;++i){
		for(auto j:pth[i]) update(tin[j],1);
		for(auto j:Q[i]){
			int t=(j.se>0?1:-1);
			ans[j.se*t]+=(query(tout[j.fi])-query(tin[j.fi]-1))*t;
		}
	}
	for(int i=1;i<=q;++i) {
		print(ans[i]);putchar('\n');
	}
	return 0;
}