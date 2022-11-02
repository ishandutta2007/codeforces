#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
long long n, k, r, t, Mx, A[200010], P[200010];
priority_queue < pair < long long , long long > > R, Q;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i < k; i++)
    {
        P[0] += A[i];
    }
    for (int i = k; i <= n; i++)
    {
        P[i - k + 1] = P[i - k] + A[i] - A[i - k];
    }
    for (int i = k + 1; i <= n - k + 1; i++)
    {
        R.push(make_pair(P[i], -i));
    }
    for (int i = 1; i <= n - 2 * k + 1; i++)
    {
        while (Q.size() > 0)
        {
            if (Q.top().f == R.top().f && Q.top().s == R.top().s)
            {
                Q.pop();
                R.pop();
                continue;
            }
            break;
        }
        if (R.size() == 0)
        {
            break;
        }
        if (P[i] + R.top().f > Mx)
        {
            Mx = P[i] + R.top().f;
            t = i;
            r = -R.top().s;
        }
        Q.push(make_pair(P[i + k], -i - k));
    }
    cout << t << " " << r;
    return (0);
}