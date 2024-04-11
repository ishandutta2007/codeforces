#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10005;
char s[N], q[3][N], r[3][N], res[N];

int main(){
	scanf("%s", s);
	int n = strlen(s);
	for(int i=0; i<n; i++){
		for(int t=i, j=2; j>=0; j--)
			q[j][i] = t % 26 + 'a', t /= 26;
	}
	for(int i=0; i<3; i++) printf("? %s\n", q[i]), fflush(stdout), scanf("%s", r[i]);
	int x;
	for(int i=0; i<n; i++){
		x = 0;
		for(int j=0; j<3; j++)
			x = x * 26 + r[j][i] - 'a';
		res[x] = s[i];
	}
	printf("! %s\n", res);
	return 0;
}