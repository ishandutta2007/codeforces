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
const int N=110000;
map<int,int>a,b,c;
int x[N];int n;
int main(){
	scanf("%d",&n);
	rep(i,1,n){scanf("%d",&x[i]);a[x[i]]++;}
	int v;
	rep(i,1,n-1){scanf("%d",&v);b[v]++;}
	rep(i,1,n-2){scanf("%d",&v);c[v]++;}
	int p1,p2;
	rep(i,1,n){
		if(a[x[i]]>b[x[i]])p1=x[i];
		if(b[x[i]]>c[x[i]])p2=x[i];
	}
	printf("%d\n%d",p1,p2);
	return 0;
}