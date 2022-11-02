#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+10;

int t,n,p,k,x,y;
char c[N];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&p,&k);
		scanf("%s",c+1);
		scanf("%d%d",&x,&y);
		int ans = 2e9+10;
		for(int i=p;i < min(n+1,p+k);i++){
			int sum = (i-p)*y;
			for(int j=i;j <= n;j += k)
				sum += c[j] == '0' ? x : 0;
			ans = min(ans,sum);
			for(int j=i;j <= n-k;j += k)
				sum += y*k-(c[j] == '0' ? x : 0) , ans = min(ans,sum);
		}
		printf("%d\n",ans);
	}
	return 0;
		
}