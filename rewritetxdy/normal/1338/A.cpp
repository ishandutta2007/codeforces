#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5+10;

int t,n,c[N]; 

inline int cal(int x){
	if(x<=0) return 0;
	int cnt = 0;
	while(x) cnt++ , x >>= 1;
	return cnt;
}

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i <= n;i++)
			scanf("%d",&c[i]);
		int las = c[1],ans = 0;
		for(int i=2;i <= n;i++){
			ans = max(ans,cal(las-c[i]));
			las = max(las,c[i]);
		}
		printf("%d\n",ans);
	}
}