#include <bits/stdc++.h>
using namespace std;
const int N=200002;
int n,m,a[N],c[N];
int mpow(int x,int y,int m){
	if(y==0) return 1%m;
	int t=mpow(x,y>>1,m);
	if(y%2==0) return t*t%m;
	return t*t%m*x%m;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); c[a[i]%m]++;
	}
	for(int i=0;i<=1000;i++)if(c[i]>1)return !printf("0\n");
	int ans=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=1LL*ans*abs(a[i]-a[j])%m;
		}
	}
	cout<<ans<<endl;
}