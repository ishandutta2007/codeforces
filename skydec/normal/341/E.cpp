#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
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
int a[1005];int n;
int f1,f2;
inline bool cmp(const int &x,const int &y){return a[x]<a[y];}
pii ans[1050000];int top;
void work(int x){
	int b[3];b[0]=f1;b[1]=f2;b[2]=x;
	sort(b,b+3,cmp);
	while(a[b[0]]&&a[b[1]]&&a[b[2]]){
		int x=a[b[1]]/a[b[0]];
		a[b[1]]-=x*a[b[0]];
		while(x){
			if(x&1){
				ans[++top]=pii(b[0],b[1]);
				a[b[0]]*=2;x/=2;
			}
			else{
				x/=2;if(!x)break;
				a[b[2]]-=a[b[0]];
				a[b[0]]*=2;
				ans[++top]=pii(b[0],b[2]);
			}
		}
		sort(b,b+3,cmp);
	}
	f1=b[1];f2=b[2];
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(a[i]){
			if(!f1)f1=i;else if(!f2)f2=i;
			else work(i);
		}
	}
	if(!f2)printf("-1\n");
	else{
		printf("%d\n",top);
		rep(i,1,top)printf("%d %d\n",ans[i].fi,ans[i].se);
	}
	return 0;
}