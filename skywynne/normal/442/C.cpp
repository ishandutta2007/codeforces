#include<bits/stdc++.h>
using namespace std;
int n, p, r;
long long c;
stack < int > S;
priority_queue < int > P;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &r);
        while (S.size() >= 2)
        {
            p = S.top();
            S.pop();
            if (!(r > p && p <= S.top()))
            {
                S.push(p);
                break;
            }
            c += min(r, S.top());
        }
        S.push(r);
    }
    while (S.size() > 0)
    {
        P.push(S.top());
        S.pop();
    }
    P.pop();
    if (n > 1)
        P.pop();
    while (P.size() > 0)
    {
        c += P.top();
        P.pop();
    }
    printf("%I64d", c);
    return (0);
}