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
int a[55];
int main(){
	int n;LL m;scanf("%d%I64d",&n,&m);m--;
	int l=1;int r=n;
	rep(i,1,n){
		if(m>=(1ll<<(n-i-1))){
			a[r--]=i;
			m-=(1ll<<(n-i-1));
		}
		else a[l++]=i;
	}
	rep(i,1,n)printf("%d ",a[i]);
	return 0;
}