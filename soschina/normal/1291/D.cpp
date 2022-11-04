#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2e5 + 2;

char s[N];
int sum[N][26], q, l, r, cnt;

int main(){
	scanf("%s%d", s + 1, &q);
	for(int i = 1; s[i]; i++){
		memcpy(sum[i], sum[i - 1], sizeof(int) * 26);
		sum[i][s[i] - 'a']++;
	}
	while(q--){
		scanf("%d%d", &l, &r);
		if((l == r) || s[l] != s[r]) puts("Yes");
		else{
			cnt = 0;
			for(int i = 0; i < 26; i++)
				if(sum[r][i] - sum[l - 1][i]) cnt++;
			puts(cnt > 2 ? "Yes" : "No");
		}
	}
	return 0;
}