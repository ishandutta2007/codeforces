#include <cstdio>
using namespace std;
const int N = 3001;

int t, n, sum;
char s[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s);
		char *end = s + n - 1;
		while(end >= s && !(*end & 1)) end--;
		if(end < s){
			puts("-1");
			continue;
		}
		sum = 0;
		for(char *c = s; c <= end; c++)
			sum += *c;
		char *begin = s;
		while(begin <= end && (sum & 1)) sum -= *begin++;
		if(begin > end){
			puts("-1");
			continue;
		}
		while(begin < end && *begin == '0') begin++;
		*(end + 1) = 0;
		puts(begin);
	}
	return 0;
}