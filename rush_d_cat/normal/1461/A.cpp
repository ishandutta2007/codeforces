#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n,k;
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++){
			printf("%c", 'a'+i%3);
		}
		printf("\n");
	}
}