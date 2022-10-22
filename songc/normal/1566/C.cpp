#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define MOD 1000000007
#define INF (1ll<<62)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N, M;
char A[101010], B[101010];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		scanf("%s", A+1);
		scanf("%s", B+1);
		int a=0, b=-3*N, c=-3*N;
		for (int i=1; A[i]; i++){
			int x=A[i]-'0', y=B[i]-'0';
			if (x + y == 1){
				b = c = a;
				a += 2;
			} 
			if (x + y == 0){
				b = a;
				a = max(a+1, c+2);
			}
			if (x + y == 2){
				c = a;
				a = max(a, b+2);
			}
		}
		printf("%d\n", a);
	}
	return 0;
}