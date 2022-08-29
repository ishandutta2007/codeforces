#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
typedef set<int>::iterator it;
bool flag=0;
int work(int a,int n,int p){
	int t=a*1ll*n/p;
	if(!t){
		if(!flag)return a;
		return max(a,p-a*n);
	}
	flag=1;
	int a1,n1,p1;a1=min(p%a,a-(p%a));
	n1=t;p1=a;
	if(a*1ll*n%p<a*1ll*(p/a-1))n1--;
	return work(a1,n1,p1);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,n,p,h;scanf("%d%d%d%d",&a,&n,&p,&h);
		flag=0;
		if(work(a%p,n,p)<=h)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}