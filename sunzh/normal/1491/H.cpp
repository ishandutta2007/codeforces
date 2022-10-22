#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n,Q;
int a[100010];
int pre[100010];
int B;
int cnt;
int belong[100010];
struct block{
	int l,r,s;
	int num;
}b[1010];
void build(int p){
	for(int i=b[p].l;i<=b[p].r;++i){
		a[i]=max(1,a[i]-b[p].s);
		if(belong[a[i]]!=p) pre[i]=a[i];
		else pre[i]=pre[a[i]];
	}
	b[p].s=0;
}
int geta(int p){
	return max(1,a[p]-b[belong[p]].s);
}
int getpre(int p){
	if(b[belong[p]].num>B)return geta(p);
	return max(1,pre[p]-b[belong[p]].s);
}
int main(){
	n=read(),Q=read();
	for(int i=2;i<=n;++i) a[i]=read();
	B=sqrt(n)+2;
	for(int i=1;i<=n;i+=B){
		b[++cnt].l=i,b[cnt].r=min(i+B-1,n);
		for(int j=i;j<=n&&j<i+B;++j) belong[j]=cnt;
	}
	for(int i=1;i<=n;++i){
		if(a[i]<b[belong[i]].l) pre[i]=a[i];
		else pre[i]=pre[a[i]];
	}
	while(Q--){
		int op=read();
		if(op==1){
			int l=read(),r=read(),x=read();
			if(belong[l]==belong[r]){
				for(int i=l;i<=r;++i){
					a[i]=max(a[i]-x,1);
					if(belong[a[i]]!=belong[i]) pre[i]=a[i];
					else pre[i]=pre[a[i]];
				}
				build(belong[l]);
			}
			else{
				for(int i=l;i<=b[belong[l]].r;++i){
					a[i]=max(a[i]-x,1);
					if(belong[a[i]]!=belong[i]) pre[i]=a[i];
					else pre[i]=pre[a[i]];
				}
				for(int i=b[belong[r]].l;i<=r;++i){
					a[i]=max(a[i]-x,1);
					if(belong[a[i]]!=belong[i]) pre[i]=a[i];
					else pre[i]=pre[a[i]];
				}build(belong[r]);
				for(int i=belong[l]+1;i<belong[r];++i){
					b[i].s+=x;
					b[i].s=min(b[i].s,1<<30);
					if(b[i].num<=B){
						build(i);
					}
					b[i].num+=x;
				}
			}
		}
		else{
			int u=read(),v=read();
			while(u!=v){
				while(belong[u]!=belong[v]){
					if(belong[u]<belong[v]) swap(u,v);
					u=getpre(u);
				}
				if(u==v) break ;
				if(getpre(u)!=getpre(v)){
					u=getpre(u),v=getpre(v);
				}
				else{
					if(u<v) swap(u,v);u=geta(u);
				}
			}
			printf("%d\n",u);
		}
	}
}