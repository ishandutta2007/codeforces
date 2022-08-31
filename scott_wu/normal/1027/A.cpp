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

int main()
{
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N; string s;
        cin >> N >> s;
        bool bad = false;
        for (int j = 0; j < N; j++)
        {
            int x = abs (s[j] - s[N-1-j]);
            if (x == 1 || x > 2)
                bad = true;
        }
        if (bad) cout << "NO\n";
        else cout << "YES\n";
    }
}