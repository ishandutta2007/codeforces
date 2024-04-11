#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5+10;

int t,n,cnt[10];
char c[N];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%s",c+1);
		n = strlen(c+1);
		for(int i=0;i <= 9;i++) cnt[i] = 0;
		for(int i=1;i <= n;i++) cnt[c[i]-'0']++;
		int ans = 0;
		for(int i=0;i <= 9;i++) ans = max(ans,cnt[i]);
		for(int x=0;x <= 9;x++)
			for(int y=0;y <= 9;y++){
				int s=0,t=x;
				for(int i=1;i <= n;i++)
					if(c[i]-'0' == t)
						s++ , t = t == x ? y : x;
				if(t == y) s--;
				ans = max(ans,s);
			}
		printf("%d\n",n-ans);
	}
	return 0;
}