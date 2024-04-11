#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
ll n,c[120];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		if(n%2050) puts("-1");
		else{
			int cnt = 0;
			n /= 2050;
			while(n) cnt += n%10 , n /= 10;
			printf("%d\n",cnt);
		}
	}
}