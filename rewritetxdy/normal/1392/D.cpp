#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5+10;

int t,n,f[N][4],q[N],cnt;
char c[N];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",c+1);
		cnt = 0;
		int las = 0,ans = 0;
		for(int i=1;i <= n;i++)
			if(c[i] != c[i+1]){
				q[++cnt] = i-las;
				las = i;
			}
		if(cnt == 1){
			printf("%d\n",(n-1)/3+1);
			continue;
		}
		if(cnt > 2 && c[1] == c[n]) q[1] += q[cnt--];
		for(int i=1;i <= cnt;i++) ans += q[i]/3;
		printf("%d\n",ans);
	}
	return 0;
}