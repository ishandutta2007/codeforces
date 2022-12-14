#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    if (N == 2) printf("NO");
    else if (N % 2) printf("NO");
    else printf("YES");
    return 0;
}