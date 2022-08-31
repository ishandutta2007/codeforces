#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j),__tmp=k;i<=__tmp;i++)
#define per(i,j,k) for(int i=(j),__tmp=k;i>=__tmp;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 51000
int index;LL tt[MAXN];
struct heap{
	int key[MAXN];
	int a[MAXN],size;
	void init(){
		size=0;
	}
	inline void up(int x){
		while(x!=1&&key[a[x]]>key[a[x/2]]){
			int tmp=a[x];a[x]=a[x/2];a[x/2]=tmp;
			x/=2;
		}
	}
	inline void down(int x){
		while(1){
			int res=x;
			if(x*2+1<=size&&key[a[x*2+1]]>key[a[res]])res=x*2+1;
			if(x*2<=size&&key[a[x*2]]>key[a[res]])res=x*2;
			int tmp=a[res];a[res]=a[x];a[x]=tmp;
			if(res==x)break;
			x=res;
		}
	}
	inline void push(int x){
		a[++size]=x;
		up(size);
	}
	inline int pop(){
		int res=a[1];
		a[1]=a[size--];
		down(1);
		return res;
	}
}b;
int t[MAXN],p[MAXN],s[MAXN];int tmp[MAXN];int page[MAXN];
int pc[MAXN];
LL fin[MAXN];
int n;
inline bool cmp(const int &x,const int &y){return t[x]<t[y];}
void ck(int xs){
	p[index]=xs;b.key[index]=xs;
	memset(fin,0,sizeof fin);
	rep(i,1,n)page[i]=s[i];
	b.init();LL now=0;
	rep(i,1,n){
		now=t[i];
		b.push(i);
		while(b.size&&(page[b.a[1]]+now<=t[i+1]||i==n)){
			int u=b.pop();
			fin[u]=now+page[u];
			now+=1ll*page[u];
		}
		if(b.size){
			page[b.a[1]]-=t[i+1]-now;
		}
	}
}
int hx[MAXN];
int main(){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		scanf("%d",&n);
		rep(i,1,n){
			scanf("%d%d%d",&t[i],&s[i],&p[i]);
			pc[i]=i;
		}
		sort(pc+1,pc+1+n,cmp);
		rep(i,1,n)tmp[i]=t[i];rep(i,1,n)t[i]=tmp[pc[i]];
		rep(i,1,n)tmp[i]=s[i];rep(i,1,n)s[i]=tmp[pc[i]];
		rep(i,1,n)tmp[i]=p[i];rep(i,1,n)p[i]=tmp[pc[i]];
		rep(i,1,n)if(p[i]==-1)index=i;
		
		rep(i,1,n)b.key[i]=p[i];
		
		sort(tmp+1,tmp+1+n);
		
		if(tmp[2]!=0)hx[++hx[0]]=tmp[2]-1;
		
		rep(i,2,n)if(tmp[i]+1!=tmp[i+1])hx[++hx[0]]=tmp[i]+1;
		
		LL FIN;scanf("%I64d",&FIN);
		
		int l=1;int r=hx[0];int res=0;
		while(l<r){
			int mid=(l+r)>>1;
			ck(hx[mid]);
			if(fin[index]>=FIN){
				res=hx[mid];l=mid+1;
			}
			else r=mid;
		}
		ck(hx[l]);if(fin[index]>=FIN)res=hx[l];
		printf("%d\n",res);
		ck(res);
		rep(i,1,n)tt[pc[i]]=fin[i];
		rep(i,1,n)printf("%I64d ",tt[i]);
		return 0;
}