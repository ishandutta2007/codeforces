#include <bits/stdc++.h>

using namespace std;

int N,a[100010],b[100010];
int cnt[100010],cnt2[100010];
int num[100010],now = 0;

int main()
{
    scanf("%d",&N);
    for (int i=1;i<=N;i++)
    {
        scanf("%d",&a[i]);
        a[i] = N - a[i];
        cnt[a[i]]++;
    }
    for (int i=1;i<=N;i++)
    {
        if (cnt[i] % i)
        {
            puts("Impossible");
            return 0;
        }
    }
    puts("Possible");
    for (int i=1;i<=N;i++)
    {
        if (cnt[a[i]] % a[i] == 0)
            num[a[i]] = ++now;
        cnt[a[i]]--;
        b[i] = num[a[i]];
        printf("%d%c",b[i]," \n"[i==N]);
    }
}