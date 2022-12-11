#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

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

const int N = 1e5+5;
const int B = 310;

int n,q;
struct STR{
	int len,st;
}st[N];
int Len;
char s[N];
struct node{
	int son[26],fa;
}trie[N];
int tot;
vector<int>pt[N],key[N];
struct query{
	int l,r,id;
	query(const int l_=0,const int r_=0,const int id_=0){l=l_;r=r_;id=id_;}
};
vector<query>qry[N];
LL ans[N];
int que[N];
int lef[N],rig[N];
int cnt[N];
LL pre[N];

void getcnt(int x){
	for(int y=lef[x];y;y=rig[y]){
		getcnt(y);
		cnt[x]+=cnt[y];
	}
	for(auto u : key[x])pre[u]=cnt[x];
}

int be[N];
int a[N],all[N];

void add(int x,int v){
	int i;
	for(i=x;i<=n&&be[i]==be[x];i++)a[i]+=v;
	for(;i<=n;i+=B)all[be[i]]+=v;
}

int request(int x){return a[x]+all[be[x]];}

void getans(int x){
	for(auto u : key[x])add(u,1);
	for(auto u : pt[x])
		for(auto v : qry[u])ans[v.id]=ans[v.id]+request(v.r)-request(v.l-1);
	for(int y=lef[x];y;y=rig[y])getans(y);
	for(auto u : key[x])add(u,-1);
}

int main(){
	n=get();q=get();
	fo(i,1,n)be[i]=(i-1)/B+1;
	fo(i,1,n){
		scanf("%s",s+Len+1);
		st[i].len=strlen(s+Len+1);
		st[i].st=Len+1;
		Len+=st[i].len;
		int now=0;
		fo(x,st[i].st,st[i].st+st[i].len-1){
			if (!trie[now].son[s[x]-'a'])trie[now].son[s[x]-'a']=++tot;
			now=trie[now].son[s[x]-'a'];
			if (st[i].len<=B)pt[now].push_back(i);
		}
		key[now].push_back(i);
	}
	fo(i,1,q){
		int l=get(),r=get(),x=get();
		qry[x].push_back(query(l,r,i));
	}
	int he=0,ta=1;
	que[1]=0;
	for(;he<ta;){
		int x=que[++he];
		fo(c,0,25)
		if (trie[x].son[c]){
			int y=trie[x].son[c];
			if (x){
				int w=trie[x].fa;
				while(w&&!trie[w].son[c])w=trie[w].fa;
				if (trie[w].son[c])w=trie[w].son[c];
				trie[y].fa=w;
			}
			que[++ta]=y;
		}
	}
	fo(i,1,tot){
		rig[i]=lef[trie[i].fa];
		lef[trie[i].fa]=i;
	}
	fo(i,1,n)
	if (st[i].len>B){
		fo(x,0,tot)cnt[x]=0;
		fo(x,0,n)pre[x]=0;
		cnt[0]++;
		for(int now=0,x=st[i].st;x<=st[i].st+st[i].len-1;x++){
			now=trie[now].son[s[x]-'a'];
			cnt[now]++;
		}
		getcnt(0);
		fo(x,1,n)pre[x]=pre[x]+pre[x-1];
		for(auto u : qry[i])ans[u.id]=pre[u.r]-pre[u.l-1];
	}
	getans(0);
	fo(i,1,q)cout<<ans[i]<<endl;
	return 0;
}