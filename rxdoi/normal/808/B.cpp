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
const int maxn=200005;
ll sum,ans;
int n,k,a[maxn];
int main(){
	n=rd(),k=rd();
	rep(i,1,n) a[i]=rd();
	rep(i,1,k) sum+=a[i];ans+=sum;
	rep(i,k+1,n) sum+=a[i]-a[i-k],ans+=sum;
	printf("%.10lf\n",1.0*ans/(n-k+1));
}