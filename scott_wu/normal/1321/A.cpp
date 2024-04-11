#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int r[110], b[110];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> r[i];
    for (int i = 0; i < N; i++)
        cin >> b[i];


    int na = 0, nb = 0;
    for (int i = 0; i < N; i++)
    {
        if (r[i] > b[i])
            na++;
        if (b[i] > r[i])
            nb++;
    }

    if (!na)
        cout << "-1\n";
    else
        cout << nb / na + 1 << "\n";
}