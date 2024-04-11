#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n,k,p[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=k;i++)p[i]=i;
		reverse(p+k-(n-k),p+k+1);
		for(int i=1;i<=k;i++)printf("%d ", p[i]);printf("\n");
	}
}