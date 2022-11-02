#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e5+10;

int n,vis[N],p[N],sum[N],cnt[N],ct; 

inline void init(){
	for(long long i=2;i <= n;i++){
		if(!vis[i])
			p[++ct] = i , cnt[1]++;
		for(long long j=1;p[j]*i <= n;j++){
			vis[i*p[j]] = 1 , cnt[i]++;
			if(i%p[j] == 0)
				break;
		}
	}
}

int main()
{
	scanf("%d",&n);
	init();
	sum[0] = 1;
	for(int i=1;i <= n;i++) sum[i] = sum[i-1]+cnt[i];
	int ans=1;
	for(int i=2;i <= n;i++)
		printf("%d ",sum[ans] < i ? ++ans : ans);
}