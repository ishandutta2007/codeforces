#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d",&n);
	__int128 ans=1;
	for(int i=0;i<n/2;++i){
		ans=ans*(n-i)/(i+1);
	}
	ans/=2;
	for(int i=2;i<n/2;++i)ans*=i*i;
	long long res=(long long)ans;
	printf("%lld\n",res);
	return 0;
}