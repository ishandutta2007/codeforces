#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 110000
struct jsb{
	int a,b;
}data[MAXN];
inline bool cmp(jsb x,jsb y){if(x.a==y.a)return x.b<y.b;return x.a<y.a;}
int n;
int main()
{
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&data[i].a,&data[i].b);
	sort(data+1,data+1+n,cmp);
	int now=0;int ANS=0;
	rep(i,1,n){
		if(data[i].b>=now)now=data[i].b,ANS=max(ANS,data[i].b);
		else now=data[i].a,ANS=max(ANS,data[i].a);
	}
	printf("%d\n",ANS);
	return 0;
}