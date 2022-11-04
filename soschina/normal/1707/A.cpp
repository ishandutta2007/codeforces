#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 1;

int t, n, q, a[N];
char s[N + 1];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int now = 0;
        s[n + 1] = 0;
        for (int i = n; i; i--){
            if(now >= a[i])
                s[i] = '1';
            else if(now < q){
                now++;
                s[i] = '1';
            }
            else
                s[i] = '0';
        }
        printf("%s\n", s + 1);
    }
	return 0;
}