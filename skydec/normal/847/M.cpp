#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=105;
int a[N];int n;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	bool ok=1;
	rep(i,3,n)ok&=(a[i]-a[i-1]==a[2]-a[1]);
	if(ok)printf("%d\n",a[n]-a[n-1]+a[n]);
	else printf("%d\n",a[n]);
	return 0;
}