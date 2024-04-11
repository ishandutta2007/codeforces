#include<bits/stdc++.h>
using namespace std;
long long n, Mx, A[100010], PS[100010], T[100010][2];
priority_queue < long long > P, Q;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i < n)
            cin >> A[i];
        PS[i + 1] = PS[i] + A[i] - (A[i] + 1) % 2;
        T[i][0] = T[i - 1][0] + A[i - 1] - A[i - 1] % 2;
        if (A[i - 1] == 1)
        {
            T[i][0] = 0;
        }
    }
    for (int i = n; i > 0; i--)
    {
        T[i][1] = T[i + 1][1] + A[i] - A[i] % 2;
        if (A[i + 1] == 1)
        {
            T[i][1] = 0;
        }
        P.push(PS[i] + T[i][1]);
    }
    /*for (int i = 1; i <= n; i++)
    {
        cout << PS[i] << " " << T[i][0] << " " << T[i][1] << endl;
    }
    cout << endl;*/
    for (int i = 1; i <= n; i++)
    {
        while (Q.size() > 0)
        {
            if (P.top() == Q.top())
            {
                P.pop();
                Q.pop();
                continue;
            }
            break;
        }
        //cout << T[i][0] << " " << P.top() << " " << PS[i] << endl;
        Mx = max(Mx, T[i][0] + P.top() - PS[i]);
        Q.push(PS[i] + T[i][1]);
    }
    if (n == 2)
        Mx = A[1];
    cout << Mx;
    return (0);
}