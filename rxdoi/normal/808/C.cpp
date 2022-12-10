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
#define pii pair<int,int>
#define pdd pair<double,double>
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
const int maxn=105;
int n,w,a[maxn],b[maxn],id[maxn];
bool cmp(int x,int y){return a[x]>a[y];}
int main(){
	n=rd(),w=rd();
	rep(i,1,n) a[i]=rd(),id[i]=i;
	sort(id+1,id+n+1,cmp);
	for (int _=1,i=id[_];_<=n;_++,i=id[_]){
		int need=(a[i]+1)/2;
		if (w<need) return puts("-1"),0;
		w-=need,b[i]=need;
	}
	for (int _=1,i=id[_];_<=n&&w;_++,i=id[_]){
		int need=min(w,a[i]-b[i]);
		b[i]+=need,w-=need;
	}
	rep(i,1,n) rt(b[i]),putchar(' ');
}