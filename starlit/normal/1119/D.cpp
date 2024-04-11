#include<bits/stdc++.h>
const int N=100005;
using namespace std;
int n,q,loc;
typedef long long ll;
ll s[N],l,r,c[N],d[N];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%lld",s+i);
	sort(s,s+n);
	for(int i=1;i<n;i++)
	c[i]=s[i]-s[i-1];
	sort(c+1,c+n);
	for(int i=1;i<n;i++)
	d[i]=d[i-1]+c[i];
	scanf("%d",&q);
	for(;q--;){
		scanf("%lld%lld",&l,&r);
		r-=l-1;
		loc=upper_bound(c+1,c+n,r)-c-1;
		printf("%lld ",r*(n-loc)+d[loc]);
	}
}