#include <bits/stdc++.h>
using namespace std;

int N, ans;

int main(){
    scanf("%d", &N);
    for (ans=0; (1<<ans)<=N; ans++);
    printf("%d", ans);
    return 0;
}