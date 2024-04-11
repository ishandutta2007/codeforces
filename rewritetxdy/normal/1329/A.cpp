#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+10;

int n,m,c[N],ans[N];
ll sum;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i <= m;i++) scanf("%d",&c[i]),  sum += c[i];
	if(sum < n){
		puts("-1");
		return 0;
	}
	for(int i=1;i <= m;i++){
		ans[i] = i;
		if(i+c[i]-1 > n){
			puts("-1");
			return 0;
		}
	}
	for(int i=m;i >= 1;i--){
		if(ans[i]+c[i]-1 <= n)
			ans[i] = n-c[i]+1 , n -= c[i];
		else break;//!!!
	}
	for(int i=1;i <= m;i++)
		printf("%d ",ans[i]);
}