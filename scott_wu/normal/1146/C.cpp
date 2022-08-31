#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

void gogo()
{
    int N; cin >> N;
    int ans = 0;
    for (int i = 0; (1 << i) < N; i++)
    {
        vector <int> a, b;
        for (int j = 0; j < N; j++)
        {
            if (j & (1 << i))
                b.push_back(j);
            else
                a.push_back(j);
        }
        cout << a.size() << " " << b.size();
        for (int x : a)
            cout << " " << x + 1;
        for (int x : b)
            cout << " " << x + 1;
        cout << endl << flush;

        int f; cin >> f;
        ans = max (ans, f);
    }
    cout << -1 << " " << ans << endl << flush;
}

int main()
{
    int T; cin >> T;
    for (int test = 0; test < T; test++)
    {
        gogo();
    }
}