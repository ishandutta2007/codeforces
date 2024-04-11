#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 300000
#define ll long long
int a[Maxn+5];
int sum[Maxn+5];
int num[(1<<20)+5][2];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	num[0][0]++;
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=num[sum[i]][i&1];
		num[sum[i]][i&1]++;
	}
	cout<<ans<<endl;
	return 0;
}