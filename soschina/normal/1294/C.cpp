#include <cstdio>
using namespace std;

int t, n, tmp, len, num[15], cnt[15];

int main(){
	scanf("%d", &t);
	while(t--){
		len = 0;
		scanf("%d", &n);
		tmp = n;
		for(int i = 2; i * i <= tmp; i++) if(tmp % i == 0){
			num[len] = i;
			cnt[len] = 0;
			do cnt[len]++, tmp /= i; while(tmp % i == 0);
			len++;
		}
		if(tmp > 1) num[len] = tmp, cnt[len] = 1, len++;
		if(len >= 3 || len == 2 && cnt[0] + cnt[1] >= 4)
			printf("YES\n%d %d %d\n", num[0], num[1], n / num[0] / num[1]);
		else if(cnt[0] >= 6)
			printf("YES\n%d %d %d\n", num[0], num[0] * num[0], n / num[0] / num[0] / num[0]);
		else printf("NO\n");
	}
	return 0;
}