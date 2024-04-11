#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;

int main(){
	scanf("%d", &N);
	for (int i=2; i<=N; i++){
		if (N%i==0){
			printf("%d%d\n", i, N/i);
			return 0;
		}
	}
	return 0;
}