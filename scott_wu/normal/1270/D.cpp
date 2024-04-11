#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K;
int ask (int x)
{
    cout << "?";
    for (int i = 1; i <= K + 1; i++)
    {
        if (i == x) continue;
        cout << " " << i;
    }
    cout << endl << flush;

    int a, b;
    cin >> a >> b;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    vector <int> v;
    for (int i = 1; i <= K + 1; i++)
    {
        v.push_back (ask (i));
    }
    sort (v.begin(), v.end());

    int ans = 0;
    while (v[ans] == v[ans+1])
        ans++;
    cout << "! " << K - ans << endl;
}