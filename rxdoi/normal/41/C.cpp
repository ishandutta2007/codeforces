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
#define rep(x,a,b) for (int x=a;x<=(int)b;x++)
#define drp(x,a,b) for (int x=a;x>=(int)b;x--)
#define cross(x,a) for (int x=hd[a];~x;x=nx[x])
#define ll long long
#define inf (1<<29)
#define PII pair<int,int>
#define PDD pair<double,double>
#define mk(a,b) make_pair(a,b)
#define fs first
#define sc second
#define pb push_back
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
char a[maxn],ans[maxn];
int main(){
	scanf("%s",a+1);
	int l=strlen(a+1),cnt=1;
	bool at=0;
	ans[1]=a[1];
	rep(i,2,l){
		if (i+2<l&&a[i]=='d'&&a[i+1]=='o'&&a[i+2]=='t') ans[++cnt]='.',i+=2;
		else if (i+1<l&&a[i]=='a'&&a[i+1]=='t'&&at==0) ans[++cnt]='@',i++,at=1;
		else ans[++cnt]=a[i];
	}
	printf("%s",ans+1);
}