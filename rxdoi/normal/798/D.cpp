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
const int maxn=100005;
struct info{
	int a,b,id;
	bool operator <(const info&x)const{return a>x.a;}
}c[maxn];
int n,k;
int main(){
	n=rd();
	rep(i,1,n) c[i].a=rd(),c[i].id=i;
	rep(i,1,n) c[i].b=rd();
	sort(c+1,c+n+1);
	rt(n/2+1),putchar('\n');
	rt(c[1].id),putchar(' ');
	for (int i=2;i<=n;i+=2){
		if (c[i].b>c[i+1].b) rt(c[i].id);else rt(c[i+1].id);
		putchar(' ');
	}
}