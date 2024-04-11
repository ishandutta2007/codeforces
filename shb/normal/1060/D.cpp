#include <bits/stdc++.h>
typedef long long LL;

using namespace std;

int N;
int L[100010],R[100010];

int main()
{
    scanf("%d",&N);
    for (int i=1;i<=N;i++)scanf("%d%d",&L[i],&R[i]);
    sort(L+1,L+N+1);
    sort(R+1,R+N+1);
    LL ans = N;
    for (int i=1;i<=N;i++) ans += max(L[i],R[i]);
    printf("%lld\n",ans);
}