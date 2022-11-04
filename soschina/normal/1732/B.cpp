#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 2;

int t, n, f[N];
char s[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d%s", &n, s + 1);
        s[0] = '0';
        for (int i = 1; i <= n; i++)
            f[i] = f[i - 1] + (s[i] != s[i - 1]);
        printf("%d\n", max(f[n] - 1, 0));
    }
	return 0;
}