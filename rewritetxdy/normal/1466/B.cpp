#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int t,n,c[100010];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int cnt = 1;
		for(int i=1;i <= n;i++) scanf("%d",&c[i]);
		for(int i=2;i <= n;i++){
			if(c[i] <= c[i-1]) c[i]++;
			if(c[i] > c[i-1]) cnt++;
		}
		printf("%d\n",cnt);
	}
	
}