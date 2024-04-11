#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
int ans;

int main(){
    int x, y;
    scanf("%d",  &N);
    for (int i=0; i<N; i++) {
        scanf("%d %d", &x, &y);
        ans = max(ans, x+y);
    }
    printf("%d", ans);
    return 0;
}