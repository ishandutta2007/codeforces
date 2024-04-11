#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=1010000;
inline void read(int &x){
	x=0;char p=getchar();int sign=1;
	while(p!='-'&&(!(p<='9'&&p>='0')))p=getchar();
	if(p=='-'){
		sign=-1;p=getchar();
	}
	while(p<='9'&&p>='0')x*=10,x+=p-48,p=getchar();
	x*=sign;
}
LL ma[N*4];LL tag[N*4];
inline void down(int me){
	if(tag[me]==0)return;
	tag[me*2]+=tag[me];tag[me*2+1]+=tag[me];
	ma[me*2]+=tag[me];ma[me*2+1]+=tag[me];
	tag[me]=0;
}
void add(int me,int l,int r,int x,int y,LL v){
	if(l^r)down(me);
	if(x<=l&&r<=y){
		tag[me]+=v;
		ma[me]+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(me*2,l,mid,x,y,v);
	if(y>mid)add(me*2+1,mid+1,r,x,y,v);
	ma[me]=ma[me*2];
	if(ma[me*2+1]>ma[me])ma[me]=ma[me*2+1];
}
int n;
struct seg{
	int l,r,a;
};
seg small[N];int stop;
seg big[N];int btop;
int main(){
	read(n);LL ans=0;
	rep(i,1,n){
		int v;read(v);
		while(stop&&small[stop].a>=v){
			add(1,1,n,small[stop].l,small[stop].r,small[stop].a);
			stop--;
		}
		add(1,1,n,small[stop].r+1,i,-v);
		small[stop+1]=(seg){small[stop].r+1,i,v};stop++;
		
		while(btop&&big[btop].a<=v){
			add(1,1,n,big[btop].l,big[btop].r,-big[btop].a);
			btop--;
		}
		add(1,1,n,big[btop].r+1,i,v);
		big[btop+1]=(seg){big[btop].r+1,i,v};btop++;
		ans=ma[1];
		if(i^n)
		add(1,1,n,i+1,i+1,ans);
	}
	printf("%I64d\n",ans);
	return 0;
}