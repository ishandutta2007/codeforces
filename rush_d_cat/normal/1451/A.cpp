#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
int main() {
	scanf("%d", &t);
	while(t--){
		int n;scanf("%d",&n);
		if(n==1){
			printf("0\n"); continue;
		}
		if(n==2){
			printf("1\n"); continue;
		}
		if(n==3){
			printf("2\n"); continue;
		}
		if(n%2==0){
			printf("2\n");
		}else{
			printf("3\n");
		}
    }
}