#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

char s[100010];
int N;

int main()
{
    scanf("%d",&N);
    scanf("%s",s);
    int cnt = 0;
    for (int i=0;i<N;i++)  cnt += (s[i] == '8');
    printf("%d\n",min(N / 11, cnt));
}