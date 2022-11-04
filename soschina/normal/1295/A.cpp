#include <cstdio>
using namespace std;
const int use[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int t, n;

int solve(int n){
	if(n >= 4) n = solve(n - 2) + 2;
	for(int i = 9; ~i; i--) if(use[i] <= n){
		putchar(i + '0');
		return n - use[i];
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		solve(n), putchar('\n');
	}
	return 0;
}