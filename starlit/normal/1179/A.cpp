#include<bits/stdc++.h>
const int N=100005;
using namespace std;
typedef long long ll;
int n,q,a[N],sa[N],sb[N],mx,mn[N];
ll x;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i);
	mx=a[1];
	for(int i=1;i<n;i++){
		sa[i]=mx,mn[i]=sb[i]=a[i+1];
		if(mx<mn[i])swap(mx,mn[i]);
	}
	for(;q--;){
		scanf("%lld",&x);
		if(x<n)printf("%d %d\n",sa[x],sb[x]);
		else{
			x=(x-1)%(n-1)+1;
			printf("%d %d\n",mx,mn[x]);
		}
	}
}