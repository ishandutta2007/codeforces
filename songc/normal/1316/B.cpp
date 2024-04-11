#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int tc, N, ansk;
char str[5050], ans[5050], c[5050];

int main(){
	scanf("%d", &tc);
	while (tc--){
		scanf("%d", &N);
		scanf("%s", str+1);
		for (int i=1; i<=N; i++) ans[i] = 'z';
		ans[N+1] = 0;
		for (int i=1; i<=N; i++){
			for (int j=i; j<=N; j++) c[j-i+1] = str[j];
			for (int j=1; j<i; j++) c[N-i+1+j] = str[j];
			if ((N-i+1) & 1) reverse(c+N-i+2, c+N+1);
			if (strcmp(ans+1, c+1) > 0) {
				for (int j=1; j<=N; j++) ans[j] = c[j];
				ansk = i;
			}
		}
		printf("%s\n", ans+1);
		printf("%d\n", ansk);
	}
	return 0;
}