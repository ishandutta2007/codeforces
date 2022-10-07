#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100100;
const int MAXC = 1000;
char s1[MAXN], s2[MAXN];

int N;
int cnt1[MAXC], cnt2[MAXC];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%s %s", s1, s2);
	N = strlen(s1);
	for(int i = 0; i < N; ++i) {
		cnt1[s1[i]]++;
		cnt2[s2[i]]++;
	}
	char cur = 'A';
	int numchng = 0;
	for(int i = 0; i < N; ++i) {
		char &c = s1[i];
		while (cur <= 'Z' && cnt2[cur] <= cnt1[cur]) cur++;
//		printf("i = %d, cur = %c\n", i, cur);
		if (cnt1[c] > cnt2[c] && (cnt2[c] == 0 || cur < c)) {
			cnt1[c]--;
			cnt2[cur]--;
			c = cur;
			++numchng;
		} else {
			cnt1[c]--;
			cnt2[c]--;
		}
	}
	printf("%d\n%s\n", numchng, s1);
	return 0;
}