#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int isBad[1000100], cntBad[1000100], event[1000100], cntHit[1000100], step[1000100];

int main()
{
    ios::sync_with_stdio(0);
    //freopen("1.txt", "r", stdin);

    int n, m, x;
    cin >> n >> m;
    for (int i = 1; i <= 1000000; i++) step[i] = oo;
    while (m--) cin >> x, isBad[x] = step[x] = 1;

    for (int i = 1; i <= 1000000; i++)
    {
        cntBad[i] = cntBad[i - 1] + isBad[i];
        if (!isBad[i]) step[i] = step[i - cntBad[i]] + 1;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> event[i];
        if (event[i] < 0) cntHit[i] = 1;
    }

    for (int i = n; i; i--) cntHit[i] += cntHit[i + 1];

    int len = 0;
    for (int i = 1; i <= n; i++)
        if (event[i] < 0)
            len -= cntBad[len];
        else
            if (cntHit[i] < step[++len])
                cout << event[i];

    if (!len) cout << "Poor stack!\n";
}