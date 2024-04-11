#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 2;

int t, n, a[N], f[N][2];
char s[N];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d%s", &n, s + 1);
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(s[i] == '1'){
                f[i][1] = max(f[i - 1][0], f[i - 1][1]) + a[i];
                f[i][0] = f[i - 1][0] + a[i - 1];
            }
            else{
                f[i][1] = f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            }
        }
        printf("%d\n", max(f[n][0], f[n][1]));
    }
	return 0;
}