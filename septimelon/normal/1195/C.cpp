#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> h1(n+1), h2(n+1);
    vector<long long> maxr1(n+1, 0), maxr2(n+1, 0);
    long long cur;
    for (int i = 1; i <= n; i++) {
        cin >> cur;
        h1[i] = cur;
    }
    for (int i = 1; i <= n; i++) {
        cin >> cur;
        h2[i] = cur;
    }
    h1[0] = 0;
    h2[0] = 0;
    maxr1[1] = h1[1];
    maxr2[1] = h2[1];
    int maxli = 1, maxri = 1;
    for (int i = 2; i <= n; i++) {
        maxr1[i] = maxr2[maxri] + h1[i];
        maxr2[i] = maxr1[maxli] + h2[i];
        if (maxr1[i] > maxr1[maxli])
            maxli = i;
        if (maxr2[i] > maxr2[maxri])
            maxri = i;
    }
    cout << max(maxr1[maxli], maxr2[maxri]) << endl;;
    return 0;
}