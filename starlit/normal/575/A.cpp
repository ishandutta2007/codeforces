#include<bits/stdc++.h>
#define rg register int
#define mi (l+r>>1)
const int N=50004;
using namespace std;
typedef long long ll;
ll S=1,T;
int n,M,m,s[N],tp[2][2];
struct mat{
	int a[2][2];
	void mul(mat&b){
		for(rg i=0,j,k;i<2;i++)
		for(k=0;k<2;k++)
		for(j=0;j<2;j++)
		tp[i][j]=(tp[i][j]+a[i][k]*1ll*b.a[k][j])%M;
		for(rg i=0,j;i<2;i++)
		for(j=0;j<2;j++)
		a[i][j]=tp[i][j],tp[i][j]=0;
	}
	void ini(int x,int y){
		a[0][0]=x,a[1][0]=y,a[0][1]=1,a[1][1]=0;
	}
}b[N*4],ans,tr;
pair<ll,int>op[N];
void build(int k,int l,int r){
	if(l<r)
	build(k<<1,l,mi),build(k<<1|1,mi+1,r),
	(b[k]=b[k<<1]).mul(b[k<<1|1]);
	else b[k].ini(s[l],s[(l+n-1)%n]);
}
void qry(int L,int R,int k=1,int l=0,int r=n-1){
	if(L>r||R<l)return;
	if(l>=L&&r<=R)
	//cerr<<"seg mul{"<<l<<' '<<r<<"}:"
	//<<b[k].a[0][0]<<','<<b[k].a[0][1]<<'|'<<b[k].a[1][0]<<','<<b[k].a[1][1]<<endl,
	ans.mul(b[k]);
	else qry(L,R,k<<1,l,mi),qry(L,R,k<<1|1,mi+1,r);
}
inline void skip(ll to){
	if(S==to)return;
//	cerr<<"??"<<S<<'~'<<to<<endl;
	to--;
	if(S/n<to/n){
		qry(S%n,n-1);
		tr=b[1];
		for(ll t=to/n-S/n-1;t;t>>=1){
			if(t&1)ans.mul(tr);
			tr.mul(tr);
		}S=to/n*n;
	}
	//cerr<<"wth "<<to%n<<endl;
	qry(S%n,to%n),S=to+1;
}
int main(){
//	freopen("dat.txt","r",stdin);
	//freopen("me.txt","w",stdout);
	scanf("%lld%d%d",&T,&M,&n);
	if(!T)return puts("0"),0;
	for(int i=0;i<n;i++)
	scanf("%d",s+i);
	build(1,0,n-1);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	scanf("%lld%d",&op[i].first,&op[i].second);
	sort(op,op+m);ans.a[0][0]=1%M;
	for(;m&&op[m-1].first>=T;m--);
	for(int i=0;S<T;i++){
	//	cerr<<"nxt "<<i<<"========\n";
		if(i==m){skip(T);break;}
		skip(op[i].first);
	//	cerr<<"now:"<<S<<endl;
//		cerr<<"ans:"<<ans.a[0][0]<<"\n";
		for(;;i++){
	//		cerr<<"tr "<<op[i].second<<'&'<<(i&&op[i-1].first==S-1?
	//		op[i-1].second:s[(S-1)%n])<<endl;
			tr.ini(op[i].second,i&&op[i-1].first==S-1?
			op[i-1].second:s[(S-1)%n]);
			ans.mul(tr),S++;
	//		cerr<<S<<"."<<op[i+1].first<<endl;
			if(i==m-1||op[i+1].first>S)
			break;
		}
		if(S<T)tr.ini(s[S%n],op[i].second),
		ans.mul(tr),S++;
	//	cerr<<"ans:"<<ans.a[0][0]<<"\n";
	}
	printf("%d",ans.a[0][0]);
}