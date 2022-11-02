#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 3e5+10;

int t,n,k;	
char c[N];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		scanf("%s",c+1);
		int cnt0 = 0 , cnt1 = 0;
		for(int i=1;i <= k;i++){
			int vis0 = 0 , vis1 = 0;
			for(int j=i;j <= n;j += k){
				if(!vis0 && c[j] == '0') vis0 = 1 , c[i] = '0';
				else if(!vis1 && c[j] == '1') vis1 = 1 , c[i] = '1';
			}
			if(c[i] == '0') cnt0++;
			else if(c[i] == '1') cnt1++;

			if(vis0 && vis1) {
				cnt0 = n;
				break;
			}
		}
		cnt0*2 <= k && cnt1*2 <= k ? puts("YES") : puts("NO");
	}
	return 0;
}