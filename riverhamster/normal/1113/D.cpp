#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10005;
char s[N];
int n;

int main(){
	// freopen("cf1113d.in", "r", stdin);
	// freopen("cf1113d.out", "w", stdout);
	scanf("%s", s+1);
	n = strlen(s+1);
	bool flag = true, equal;
	// printf("n = %d (n+3)/2 = %d\n", n, (n+3)/2);
	for(int i=(n+3)/2; i<=n; i++)
		if(s[1] != s[i]) flag = false;
	if(flag){
		puts("Impossible");
		return 0;
	}
	for(int i=1; i<=n; i++) s[i+n] = s[i];
	int l, r;
	for(int i=2; i<=n; i++){
		l = i; r = i + n - 1;
		flag = true; equal = true;
		while(l < r){
			if(s[l] != s[r]){
				flag = false;
				break;
			}
			if(s[l] != s[l-i+1] || s[r] != s[r-i+1]) equal = false;
			++l; --r;
		}
		if(l == r && s[l] != s[l-i+1]) equal = false;
		if(flag && !equal){
			// printf("[%d, %d] is palindrome.\n", i, i+n-1);
			puts("1");
			return 0;
		}
	}
	puts("2");
	return 0;
}