#include <cstdio>
using namespace std;
const int N = 100;

int t, n, p[N], c[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d%d", p + i, c + i);
		bool flag = c[0] <= p[0];
		for(int i = 1; i < n && flag; i++)
			flag = p[i - 1] <= p[i] && c[i - 1] <= c[i] && c[i] - c[i - 1] <= p[i] - p[i - 1];
		puts(flag ? "YES" : "NO");
	}
	return 0;
}