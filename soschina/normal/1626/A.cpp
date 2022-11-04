#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 53;

int t, n;
char s[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		n = strlen(s);
		sort(s, s + n);
		printf("%s\n", s);
	}
	return 0;
}