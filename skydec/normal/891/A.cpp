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
const int N=2005;
int n,a[N];
int gcd(int a,int b){
	if((!a)||(!b))return a+b;
	return gcd(b,a%b);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	int d=0;
	rep(i,1,n)d=gcd(d,a[i]);
	if(d!=1){
		printf("-1");
		return 0;
	}
	int ans=0;
	rep(i,1,n)if(a[i]!=1)++ans;
	if(ans!=n){
		printf("%d\n",ans);
		return 0;
	}
	int bb=n*10;
	rep(l,1,n){
		int g=0;
		rep(r,l,n){
			g=gcd(g,a[r]);
			if(g==1)bb=min(bb,(r-l)+n-1);
		}
	}
	printf("%d\n",bb);
	return 0;
}