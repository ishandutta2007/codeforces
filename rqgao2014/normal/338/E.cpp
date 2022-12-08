#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=150005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}
 
struct node{int x,y;}q[N];
int n,m,h,a[N],b[N],ans,p[N<<2],flag[N<<2];
bool emp[N<<2];

void add(int k,int b){p[k]+=b;flag[k]+=b;}
void push(int k){
	if(!flag[k]) return;
	add(ls,flag[k]);add(rs,flag[k]);
	flag[k]=0;
}
void del(int l,int r,int x,int y,int k,int up){
	if(p[k]>=up||emp[k]) return;
	if(l==r){emp[k]=1;return;}
	push(k);
	int mid=l+r>>1;
	if(x<=mid) del(l,mid,x,y,ls,up);
	if(y>mid) del(mid+1,r,x,y,rs,up);
	emp[k]=emp[ls]&emp[rs];
}
void add(int l,int r,int x,int y,int k){
	if(x<=l&&r<=y){add(k,1);return;}
	push(k);
	int mid=l+r>>1;
	if(x<=mid) add(l,mid,x,y,ls);
	if(y>mid) add(mid+1,r,x,y,rs);
	p[k]=min(p[ls],p[rs]);
}
void get(int l,int r,int k){
	if(l==r){
		if(l<=n-m+1&&!emp[k]) ans++;
		return;
	}
	int mid=l+r>>1;
	get(l,mid,ls);get(mid+1,r,rs);
}
inline bool cmp(node a,node b){return a.x>b.x;}
int main(){
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),q[i]=(node){a[i],i};
	sort(q+1,q+n+1,cmp);
	for(int i=1;i<=n;i++){
		int k=q[i].y,pos=lower_bound(b+1,b+m+1,h-a[k])-b-1;
//		printf("%d %d\n",k,pos);
		del(1,n,max(1,k-m+1),k,1,pos);
		add(1,n,max(1,k-m+1),k,1);
	}
	get(1,n,1);
	printf("%d\n",ans);
	return 0;
}