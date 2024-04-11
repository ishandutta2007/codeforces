#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int n, k, t, Mx, A[100005];
pair < int , int > Pr;
priority_queue < pair < int , int > > P, Q;
vector < pair < int , int > > V;
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
        Pr.f = A[i];
        Pr.s = i;
        P.push(Pr);
        Pr.f = -A[i];
        Q.push(Pr);
        while (P.top().f + Q.top().f > k)
        {
            if (P.top().s == i)
            {
                t = Q.top().s;
                Q.pop();
            }
            else if (Q.top().s == i)
            {
                t = P.top().s;
                P.pop();
            }
            while (Q.top().s < t)
            {
                Q.pop();
            }
            while (P.top().s < t)
            {
                P.pop();
            }
        }
        Mx = max(Mx, i - t);
    }
    while (P.size() > 0)
        P.pop();
    while (Q.size() > 0)
        Q.pop();
    t = 0;
    for (int i = 1; i <= n; i++)
    {
        Pr.f = A[i];
        Pr.s = i;
        P.push(Pr);
        Pr.f = -A[i];
        Q.push(Pr);
        while (P.top().f + Q.top().f > k)
        {
            if (P.top().s == i)
            {
                //cout << i << endl;
                t = Q.top().s;
                Q.pop();
            }
            else if (Q.top().s == i)
            {
                //cout << P.top().f << " " << Q.top().f << endl;
                t = P.top().s;
                P.pop();
            }
            while (Q.top().s < t)
            {
                Q.pop();
                //c --;
            }
            while (P.top().s < t)
            {
                P.pop();
                //c --;
            }
        }
        //cout << c << "::" << t << endl;
        if (i - t == Mx)
        {
            Pr.f = t + 1;
            Pr.s = i;
            V.push_back(Pr);
        }
    }
    printf("%d %d\n", Mx, V.size());
    for (int i = 0; i < V.size(); i++)
    {
        printf("%d %d\n", V[i].f, V[i].s);
    }
    return (0);
}