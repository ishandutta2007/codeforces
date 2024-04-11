#include<bits/stdc++.h>
using namespace std;
typedef long long lxl;
const int MAXN=3e5+5;
const int MAXB=605;

int n,m,block;
int a[MAXN];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))(ch=='-')&&(f=-f),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}

#define lowbit(x) (x&(-x))
int tree1[MAXN];
lxl tree2[MAXN];
inline void add(int pos,int val){
	for(;pos<=m;pos+=lowbit(pos)) ++tree1[pos],tree2[pos]+=val;
}
inline pair<int,lxl> query(int l,int r){
	int ans1=0;lxl ans2=0;
	for(;r;r-=lowbit(r)) ans1+=tree1[r],ans2+=tree2[r];
	for(--l;l;l-=lowbit(l)) ans1-=tree1[l],ans2-=tree2[l];
	return make_pair(ans1,ans2);
}
#undef lowbit

int belong[MAXN];
struct Block{
	private:
		int n;
		struct Node{
			int size;
			lxl sum,f[MAXB];
		}b[MAXB];
	public:
		inline void build(int m){
			n=m;
			int i;
			for(i=1;i<=belong[n];++i) b[i].size=block;
			b[belong[n]].size=(n-1)%block+1;
		}
		inline void clear(){
			for(int i=1;i<=belong[n];++i){
				b[i].sum=0;
				for(int j=1;j<=b[i].size;++j)
					b[i].f[j]=0;
			}
		}
		inline void add(int pos,int val){
			int x=belong[pos];pos=(pos-1)%block+1;
			for(int i=pos;i<=b[x].size;++i) b[x].f[i]+=val;
			for(int i=x;i<=belong[n];++i) b[i].sum+=val;
		}
		inline lxl query(int pos){
			int x=belong[pos];pos=(pos-1)%block+1;
			return b[x-1].sum+b[x].f[pos];
		}
}B;	

lxl p[MAXN];

int main(){
	int i,l,r;
	n=read();
	for(i=1;i<=n;++i) m=max(m,a[i]=read());
	block=sqrt(m);
	for(i=1;i<=m;++i) belong[i]=(i-1)/block+1;
	B.build(m);
	for(i=1;i<=n;++i){
		lxl ans=0;
		for(l=1;l<=a[i];l=r+1){
			r=a[i]/(a[i]/l);
			ans+=(a[i]/l)*(B.query(r)-B.query(l-1));
		}
		ans=1ll*(i-1)*a[i]-ans;
		for(l=0;l<=m;l+=a[i]){
			pair<int,lxl> sum=query(max(1,l),min(l+a[i]-1,m));
			ans+=sum.second-1ll*sum.first*l;
		}
		printf("%lld ",p[i]=p[i-1]+ans);
		add(a[i],a[i]);B.add(a[i],a[i]);
	}
	return 0;
}