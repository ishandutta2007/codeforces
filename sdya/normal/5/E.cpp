#include <iostream>
#include <stack>

using namespace std;

int n, t, m, a[1 << 20], b[1 << 20], u[1 << 20];
stack < pair < int, int > > s;
long long ans = 2LL;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i ++) if (a[i] > a[t]) t = i;
    for (int i = t; i < t + n; i ++) b[i - t] = a[i % n];
    
    for (int i = 1; i < n; i ++)
        if (s.empty()) s.push(make_pair(b[i], 1)); else
        {
            m = 1;
            while (!s.empty() && s.top().first <= b[i])
            {
                ans += (long long)(s.top().second);
                if (s.top().first == b[i]) m += s.top().second;
                s.pop();
            }

            if (!s.empty()) ans ++;
            s.push(make_pair(b[i], m));
        }

    m = b[1]; u[1] = u[n - 1] = 1; 
    for (int i = 2; i < n; i ++) 
        if (b[i] >= m) ans += !u[i], u[i] = 1, m = b[i];
    m = b[n - 1];
    for (int i = n - 2; i > 0; i --)
        if (b[i] >= m) ans += !u[i], u[i] = 1, m = b[i];

    cout << ans << endl;
    return 0;
}