#include<bits/stdc++.h>
#define pil pair<int,long long>
#define mp make_pair
#define X1 first
#define Y1 second
using namespace std;

int n;
long long a[200005];
map<pil,long long> g;
bool cmp(long long x,long long y){
	return x>y;
}
long long f(int i,long long x){
	if(g.count(mp(i,x)))return g[mp(i,x)];
	if(i==n-1)return (x-1)*n;
	long long &ans=g[mp(i,x)];i++;
	if(x<=a[i]){
		int u=upper_bound(a+i,a+n,x,cmp)-a;
		return ans=f(u-1,x);
	}
	long long tmp=f(i,a[i])+(x-x%a[i]-a[i])*i;
	if(x%a[i]){
		long long s=f(i,x%a[i])+(x-x%a[i])*i;
		tmp=max(tmp,s);
	}
	return ans=tmp;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<n;i++)a[i]=min(a[i],a[i-1]);
	printf("%lld\n",f(0,a[0]));
	return 0;
}