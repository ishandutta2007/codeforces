#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
char str[202020];

int main(){
    scanf("%d", &N);
    scanf("%s", str);
    for (int i=0; i<N; i++) {
        if (str[i] > str[i+1]) {
            printf("%s", str+i+1);
            return 0;
        }
        printf("%c", str[i]);
    }
    return 0;
}