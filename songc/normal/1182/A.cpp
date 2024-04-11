#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 2147483647
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
int D[110];

int main(){
    scanf("%d", &N);
    if (N&1) printf("0");
    else printf("%d", 1<<(N/2));
    return 0;
}