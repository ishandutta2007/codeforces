#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5+10;

int t,n,c[N];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i <= n;i++) scanf("%d",&c[i]) , c[i] = c[i] != i;
		int cnt = 0;
		for(int i=1;i <= n;i++) if(c[i] != c[i-1]) cnt++;
		if(!cnt) puts("0");
		else if(cnt <= 2) puts("1");
		else puts("2");
	}
}