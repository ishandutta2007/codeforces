#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, eight;
char str[110];

int main(){
    scanf("%d", &N);
    scanf("%s",str);
    for (int i=0; i<N; i++) if (str[i] == '8') eight++;
    printf("%d\n", min(eight, N/11));
    return 0;
}