#include <cstdio>
using namespace std;
const int N = 1e5 + 1, val[2] = {1, -1};

int t, n, x, sum, cnt, ans;
char s[N];

int main(){
	scanf("%d", &t);
	while(t--){
		cnt = sum = ans = 0;
		scanf("%d%d%s", &n, &x, s);
		for(int i = 0; i < n; i++)
			sum += val[s[i] -= '0'];
		if(!sum){
			bool flag = false;
			for(int i = 0; i < n && !flag; i++){
				flag = cnt == x;
				cnt += val[s[i]];
			}
			printf("%s\n", flag ? "-1" : "0");
			continue;
		}
		for(int i = 0; i < n; i++){
			if(1ll * (x - cnt) * sum >= 0 && (x - cnt) % sum == 0)
				ans++;
			cnt += val[s[i]];
		}
		printf("%d\n", ans);
	}
	return 0;
}