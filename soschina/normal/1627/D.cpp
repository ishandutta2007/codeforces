#include <cstdio>
using namespace std;
const int N = 1e6 + 1;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int n, a, ans;
bool vis[N];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		vis[a] = true;
	}
	for(int i = N - 1; i > 0; i--) if(!vis[i]){
		int now = 0;
		for(int j = (N - 1) / i; j > 1; j--) if(vis[j * i])
			now = gcd(now, j);
		if(now == 1)
			ans++;
	}
	printf("%d", ans);
	return 0;
}