#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll t,n,m;

int main()
{
	cin>>t;
	while(t--){
		cin>>n>>m;
		if(m == 1) puts("NO");
		else{
			puts("YES");
			printf("%lld %lld %lld\n",n*m,n,n*m+n);
		}
	}
}