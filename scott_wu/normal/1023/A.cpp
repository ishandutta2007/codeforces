#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;

int N, M;
string s, t;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> M >> s >> t;

    int sloc = -1;
    for (int i = 0; i < N; i++)
        if (s[i] == '*')
            sloc = i;

    if (sloc == -1)
    {
        if (s == t)
            cout << "YES\n";
        else
            cout << "NO\n";
        return 0;
    }

    if (N > M + 1)
    {
        cout << "NO\n";
        return 0;
    }

    bool bad = false;
    for (int i = 0; i < sloc; i++)
        if (s[i] != t[i])
            bad = true;
    for (int i = 1; N - i > sloc; i++)
        if (s[N-i] != t[M-i])
            bad = true;
    if (!bad) cout << "YES\n";
    else cout << "NO\n";
}