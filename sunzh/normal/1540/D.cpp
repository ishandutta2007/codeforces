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
int tre[100010];
void upd(int x,int k){
	while(x<=n) tre[x]+=k,x+=x&-x;
}
int qry(int x){
	int nw=0;
	for(int i=17;i>=0;--i){
		if(nw+(1<<i)>n) continue ;
		if(tre[nw+(1<<i)]<=x){
			nw+=(1<<i);x-=tre[nw];
		}
	}
	return nw+1;
}
int b[100010];
const int B=255,N=1e5+5;
int bel[100010];
struct block{
	int l,r;
	int val[B+50],f[B+50];
	void build(){
		for(int i=l;i<=r;++i) val[i-l+1]=b[i],f[i-l+1]=0;
		for(int i=1;i<=r-l+1;++i){
			int t=qry(val[i]);
			// printf("i:%d,t:%d\n",i,t);
			f[i]=t;upd(t,1);
		}
		for(int i=1;i<=r-l+1;++i) upd(f[i],-1);
		sort(f+1,f+r-l+2);
	}
	int get(int p){
		int tmp=val[p-l+1]+1;
		// printf("tmp:%d\n",tmp);
		for(int i=p+1;i<=r;++i){
			if(val[i-l+1]<tmp) tmp++;
			// printf("i:%.d,tmp:%d\n",i,tmp);
		}
		return tmp;
	}
	int trans(int x){
		int L=1,R=r-l+1,res=0;
		while(L<=R){
			int mid=L+R>>1;
			if(f[mid]<=x) res=mid,L=mid+1;else R=mid-1;
		}
		return x+res;
	}
}bl[N/B+5];
int cnt;
int main(){
	n=read();
	for(int i=1;i<=n;++i) scanf("%d",&b[i]),upd(i,1);
	for(int i=1;i<=n;i+=B){
		bl[++cnt].l=i,bl[cnt].r=min(n,i+B-1);
		for(int j=0;j<B&&i+j<=n;++j) bel[i+j]=cnt;
		bl[cnt].build();
	}
	int Q=read();
	while(Q--){
		int op;scanf("%d",&op);
		if(op==1){
			int i,x;scanf("%d %d",&i,&x);
			b[i]=x;bl[bel[i]].build();
		}
		else{
			int p;scanf("%d",&p);
			int x=bl[bel[p]].get(p);
			for(int i=bel[p]+1;i<=cnt;++i){
				// printf("I:%d\n",i);
				x=bl[i].trans(x);
			}
			// printf("x:%d\n",x);
			printf("%d\n",n-x+1);
		}
	}
}