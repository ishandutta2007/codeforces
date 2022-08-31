#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=1005;
int n;
int ans=0;
char a[N][9];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%s",a[i]+1);
	rep(j,1,7){
		int res=0;
		rep(i,1,n)if(a[i][j]=='1')++res;
		ans=max(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}