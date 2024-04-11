#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n,q; char s[N];
int main() {
	scanf("%d", &t);
	while(t--){
		scanf("%d%d",&n,&q);
		scanf("%s",s+1);
		for(int i=1;i<=q;i++){
			int l,r;
			scanf("%d%d",&l,&r);
			//printf("l=%d,r=%d\n", l,r);
			bool ok=false;
			for(int i=l-1;i>=1;i--){
				//printf("i=%d\n", i);
				if(s[i]==s[l])ok=true;
			}
			
			for(int i=r+1;i<=n;i++){
				//printf("i==%d\n", i);
				if(s[i]==s[r])ok=true;
			}

			printf("%s\n", ok?"YES":"NO");
		}

    }
}