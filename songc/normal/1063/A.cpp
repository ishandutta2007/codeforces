#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
char str[101010];

int main(){
    scanf("%d", &N);
    scanf("%s", str);
    sort(str, str+N);
    printf("%s", str);
    return 0;
}