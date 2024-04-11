#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if(n > 30)printf("%d\n", m);
    else printf("%d\n", m % (1 << n));
}