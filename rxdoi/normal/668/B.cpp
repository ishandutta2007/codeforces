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
const int maxn=1000005;
int odd=0,eve=0,fir=1;
int n,q,ans[maxn];
int main(){
	n=rd(),q=rd();
	rep(i,1,q){
		int opt=rd();
		if (opt==1){
			int x=rd();
			if (x&1){
				if (fir) eve++;else odd++;
				fir^=1,x--;
			}
			odd+=x/2,eve+=x/2;
		}
		else fir^=1;
		odd=(odd%(n/2)+(n/2))%(n/2);
		eve=(eve%(n/2)+(n/2))%(n/2);
	}
	rep(i,1,n/2) ans[fir?odd*2+1:odd*2+2]=i*2-1,odd=(odd+1)%(n/2);
	rep(i,1,n/2) ans[fir?eve*2+2:eve*2+1]=i*2,eve=(eve+1)%(n/2);
	rep(i,1,n) rt(ans[i]),putchar(' ');
}