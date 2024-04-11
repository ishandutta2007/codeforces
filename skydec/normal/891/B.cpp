#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N=25;
int a[N],n;
int id[N];
int ans[N];
inline bool cmp(const int &x,const int &y){return a[x]<a[y];}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)id[i]=i;
	sort(id+1,id+1+n,cmp);
	rep(i,1,n-1)if(a[id[i]]==a[id[i+1]]){
		printf("-1\n");
		return 0;
	}
	rep(i,1,n)ans[id[i]]=a[id[i%n+1]];
	rep(i,1,n)printf("%d ",ans[i]);printf("\n");
	return 0;
}