#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
using namespace std;

inline void read(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}
inline void upt(int &x,int y){
	if(x>y) x=y;
}

const int N=200005,inf=1e9;
const char tar[]="2016",ned[]="2017";
struct node{
	int a[4][4];
}p[N<<2],clr,temp[5],seg[10],res;
int n,m,pre[N][4],now[4];
char s[N];

inline node merge(node a,node b){
	node tmp;
	for(int l=0;l<4;l++)
		for(int r=l;r<4;r++){
			tmp.a[l][r]=inf;
			for(int k=l;k<=r;k++)
				upt(tmp.a[l][r],a.a[l][k]+b.a[k][r]);
		}
	return tmp;
}
inline void build(int l,int r,int k){
	if(l==r){
		for(int i=0;i<4;i++)
			if(s[l]==tar[i]) p[k].a[i][i]=1;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,ls);build(mid+1,r,rs);
	p[k]=merge(p[ls],p[rs]);
}
node get(int l,int r,int x,int y,int k){
	if(l>=x&&r<=y) return p[k];
	int mid=l+r>>1,vl=0,vr=0;
	node L,R;
	if(x<=mid) vl=1,L=get(l,mid,x,y,ls); 
	if(y>mid) vr=1,R=get(mid+1,r,x,y,rs);
	if(!vl) return R;
	if(!vr) return L;
	return merge(L,R);
}

int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	build(1,n,1);
	for(int i=1;i<=n+1;i++){
		for(int j=0;j<4;j++) pre[i][j]=now[j];
		for(int j=0;j<4;j++) if(ned[j]==s[i]) now[j]=i;
	}
	while(m--){
		int l,r,k,last,si=0;read(l);read(r);
		k=r+1;
		for(int i=3;~i;i--) k=pre[k][i];
		if(k<l){puts("-1");continue;}
		k=pre[r+1][3];last=r;
		for(int i=2;~i;i--){
			k=pre[k][i];
			if(k+1<=last) seg[++si]=get(1,n,k+1,last,1);
			seg[++si]=clr;seg[si].a[i][i]=inf;
			last=k-1;
		}
		if(l<=k-1) res=get(1,n,l,k-1,1); else res=clr;
		for(int i=si;i;i--) res=merge(res,seg[i]);
		printf("%d\n",res.a[0][3]);
	}
	return 0;
}