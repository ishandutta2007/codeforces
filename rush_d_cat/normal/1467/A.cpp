#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int  t, n;

int main() {
	scanf("%d", &t);
	while (t --){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int x = i<=1?9-i:9+(i-2); 
			x=(x%10+10)%10; printf("%d", x);
		}
		printf("\n");
	}	
}