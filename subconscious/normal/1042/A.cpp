#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=105;
int a[N],n,m,s0;
int main(){
	scanf("%d",&n);
	scanf("%d",&m);s0=0;
	rep(i,n)scanf("%d",a+i),s0=max(s0,a[i]);
	rep(i,m){
		int mx=n;
		rep(j,n-1)if(a[mx]>a[j])mx=j;
		++a[mx];
	}
	int ans=0;
	rep(i,n)ans=max(ans,a[i]);
	printf("%d %d\n",ans,s0+m);
	return 0;
}