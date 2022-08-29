#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
int main(){
	int n;scanf("%d",&n);
	int ans=n*4;
	rep(a,1,n){
		int b=(n+a-1)/a;
		ans=min(ans,2*(a+b));
	}
	printf("%d\n",ans);
	return 0;
}