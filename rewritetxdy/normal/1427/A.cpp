#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int t,n,c[55];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i <= n;i++) scanf("%d",&c[i]);
		sort(c+1,c+1+n);
		int sum = 0;
		for(int i=1;i <= n;i++) sum += c[i];
		if(!sum) puts("NO");
		else{
			puts("YES");
			if(sum < 0){
				for(int i=1;i <= n;i++) printf("%d ",c[i]);puts("");
			}
			else{
				for(int i=n;i >= 1;i--) printf("%d ",c[i]);puts("");
			}
		}
	}
}