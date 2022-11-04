#include <cstdio>
using namespace std;
const int N = 2e5 + 1;

int t, cnt[2];
char s[N];

int main(){
	scanf("%d", &t);
	while(t--){
		cnt[0] = cnt[1] = 0;
		scanf("%s", s);
		for(char *c = s; *c; c++)
			cnt[*c - '0']++;
		printf("%d\n", cnt[0] == cnt[1] ? cnt[0] - 1 : (cnt[0] > cnt[1] ? cnt[1] : cnt[0]));
	}
	return 0;
}