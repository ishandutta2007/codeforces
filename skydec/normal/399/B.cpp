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
int n;char a[55];
int main(){
	scanf("%d",&n);
	LL ans=0;
	scanf("%s",a+1);
	per(i,n,1){
		ans*=2ll;
		if(a[i]=='B')ans++;
	}
	printf("%I64d\n",ans);
	return 0;
}