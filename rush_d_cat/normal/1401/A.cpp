#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200000 + 10;
int t;
int n, k;

int main() {
	scanf("%d", &t);
	while (t--){
		scanf("%d%d",&n,&k);
		if(n<=k) printf("%d\n", k-n);
		else {
			if(n%2!=k%2) printf("1\n");
			else printf("0\n");
		}
	}
}