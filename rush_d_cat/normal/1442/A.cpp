#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int t,n,a[N];
int main() {
	scanf("%d", &t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int p=a[1],s=0;
		bool ok=1;
		for(int i=2;i<=n;i++){
			int x=min(p,a[i]-s);
			int y=a[i]-x;
			if(x<0||y<0){
				ok=0; break;
			}
			p=min(p,x);
			s=max(s,y);
		}
		printf("%s\n", ok?"YES":"NO");
    }
}