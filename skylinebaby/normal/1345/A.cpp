#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        if(n < m) swap(n, m);
        if(m == 1) printf("YES\n");
        else if (n == 2) printf("YES\n");
        else printf("NO\n");     
    }
    return 0;
}