#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int t,n;
char c[100010];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%s",c+1);
		n = strlen(c+1);
		c[n+1] = c[n+2] = c[n+3] = 0;
		int cnt=0;
		for(int i=2;i <= n;i++){
			if(c[i] == c[i-2] || c[i] == c[i-1])
				for(int j=0;j <= 25;j++)
					if('a'+j != c[i-2] && 'a'+j != c[i-1] && 'a'+j != c[i+1] && 'a'+j != c[i+2]){
						c[i] = 'a'+j; cnt++ ; break;
					}
		}
		printf("%d\n",cnt);
	}
}