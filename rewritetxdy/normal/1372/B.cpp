#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int t,n;

inline int cal(int n){
	for(int i=2;i*i <= n;i++)
		if(n%i == 0) return n/i;
	return 1;
}

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d %d\n",cal(n),n-cal(n));
	}
}