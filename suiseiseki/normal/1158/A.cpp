#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define Maxn 100000
int a[Maxn+5];
int b[Maxn+5];
int n,m;
ll ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	sort(b+1,b+1+m);
	if(m==1||n==1){
		if(b[1]!=a[n]){
			puts("-1");
			return 0;
		}
	}
	if(b[1]<a[n]){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans+=1ll*a[i]*m;
	}
	if(b[1]!=a[n]){
		ans-=b[1]-a[n];
		ans+=b[1]-a[n-1];
	}
	for(int i=1;i<=m;i++){
		ans+=b[i]-a[n];
	}
	cout<<ans<<endl;
	return 0;
}