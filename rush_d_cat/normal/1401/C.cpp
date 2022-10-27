#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100000 + 10;
int t;
int n,a[N],b[N];

int main() {
	scanf("%d", &t);
	while (t--){
		scanf("%d",&n);
		int mn=1e9 + 1;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]); mn=min(mn,a[i]); b[i]=a[i];
		}
		sort(b+1,b+1+n);
		bool ok=true;
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i] && a[i]%mn) ok=false;
		}
		printf("%s\n", ok?"YES":"NO");
	}
}