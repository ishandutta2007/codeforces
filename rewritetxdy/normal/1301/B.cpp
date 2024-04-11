#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 

using namespace std;
typedef long long ll;
const int N = 1e5+10;

int t,n,c[N];

inline int abss(int x){
	return x > 0 ? x : -x;
}

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i <= n;i++)
			scanf("%d",&c[i]);
		int maxx = -2,minn = 2e9,ans = 0;
		for(int i=1;i < n;i++){
			if(c[i] != -1 && c[i+1] != -1)
				ans = max(ans,abss(c[i]-c[i+1]));
			else if(c[i] != -1)
				maxx = max(maxx,c[i]) , minn = min(minn,c[i]);
			else if(c[i+1] != -1)
				maxx = max(maxx,c[i+1]) , minn = min(minn,c[i+1]);
		}
		if(maxx >= 0 && minn <= 1e9)
			ans = max(ans,(maxx-minn+1)>>1);
		printf("%d %d\n",ans,(maxx+minn)>>1);
	}
	return 0;
}