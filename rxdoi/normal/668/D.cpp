//   Author:Arturia
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#include<bitset>
#include<vector>
#define rep(x,a,b) for (int x=a;x<=(int)(b);x++)
#define drp(x,a,b) for (int x=a;x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];~x;x=nx[x])
#define ll long long
#define inf (1<<29)
#define PII pair<int,int>
#define PDD pair<double,double>
#define mk(a,b) make_pair(a,b)
#define fs first
#define sc second
#define pb push_back
#define VI vector<int>
#define VS vector<string>
using namespace std;
inline ll rd(){
	ll x=0;int ch=getchar(),f=1;
	while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
	if (ch=='-'){f=-1;ch=getchar();}
	while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
inline void rt(ll x){
	if (x<0) putchar('-'),x=-x;
	if (x>=10) rt(x/10),putchar(x%10+'0');
		else putchar(x+'0');
}
const int maxn=100005;
struct query{
	int opt,tm,id;
	query(int a=0,int b=0,int c=0){opt=a,tm=b,id=c;}
};
map<int,int>ex;
int cnt,bit[maxn],dsc[maxn],dc;
inline int lowbit(int x){return x&-x;}
void M(int ps,int v){
	for (;ps<=dc;ps+=lowbit(ps)) bit[ps]+=v;
}
int Q(int ps){
	int ret=0;
	for (;ps;ps-=lowbit(ps)) ret+=bit[ps];
	return ret;
}
vector<query>a[maxn];
int n,ans[maxn];
int main(){
	n=rd();
	memset(ans,-1,sizeof ans);
	rep(i,1,n){
		int opt=rd(),t=rd(),x=rd();
		if (ex[x]) x=ex[x];else x=ex[x]=++cnt;
		a[x].pb(query(opt,t,i));
	}
	rep(i,1,cnt){
		dc=0;
		rep(j,0,a[i].size()-1) dsc[++dc]=a[i][j].tm;
		sort(dsc+1,dsc+dc+1);
		dc=unique(dsc+1,dsc+dc+1)-dsc-1;
		rep(j,0,a[i].size()-1){
			a[i][j].tm=lower_bound(dsc+1,dsc+dc+1,a[i][j].tm)-dsc;
			int opt=a[i][j].opt,tm=a[i][j].tm,id=a[i][j].id;
			if (opt==1) M(tm,1);
			if (opt==2) M(tm,-1);
			if (opt==3) ans[id]=Q(tm);
		}
		rep(j,0,a[i].size()-1){
			int opt=a[i][j].opt,tm=a[i][j].tm,id=a[i][j].id;
			if (opt==1) M(tm,-1);
			if (opt==2) M(tm,1);
		}
	}
	rep(i,1,n) if (ans[i]!=-1) rt(ans[i]),putchar('\n');
}