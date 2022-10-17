#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 400
#define Maxm 250000
#define ll long long
int a[Maxn+5];
int f[Maxn+5][Maxn+5][Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
ll mx(ll a,ll b){
	return a>b?a:b;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			f[i][j][0]=a[j]-a[i];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			int w=i;
			for(int j=i;j<=n;j++){
				while(w<j&&mx(f[i][w][k-1],a[j]-a[w])>mx(f[i][w+1][k-1],a[j]-a[w+1])){
					w++;
				}
				f[i][j][k]=mx(f[i][w][k-1],a[j]-a[w]);
			}
		}
	}
	ll ans=0;
	int s,_f,c,r;
	while(m--){
		scanf("%d%d%d%d",&s,&_f,&c,&r);
		ans=mx(ans,(ll)f[s][_f][r]*c);
	}
	cout<<ans<<endl;
	return 0;
}