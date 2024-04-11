#include <bits/stdc++.h>

using namespace std;

bool isOk(long long a)
{
    int s = sqrt(a + 0.5);

    if ((long long)s * s != a)
        return false;

    if (s == 1)
        return false;

    for(int i = 2; i * i <= s; ++i)
    {
        if (s % i == 0)
            return false;
    }

    return true;

}

void solve()
{
    int queriesNumber;
    cin >> queriesNumber;

    while(queriesNumber--)
    {
        long long cur;
        cin >> cur;
        puts(isOk(cur) ? "YES" : "NO");
    }
}

int main()
{
    solve();
    return 0;
}