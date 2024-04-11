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

bool q (int x1, int x2, int y1, int y2)
{
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    string s; cin >> s;
    if (s[0] == 'Y') return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N; cin >> N;
    int cx = 1, cy = 1;
    vector <char> res;
    for (int i = 0; i < N - 1; i++)
    {
        if (q (cx + 1, N, cy, N))
        {
            cx++;
            res.push_back('D');
        }
        else
        {
            cy++;
            res.push_back('R');
        }
    }

    vector <char> rres;
    cx = cy = N;
    for (int i = 0; i < N - 1; i++)
    {
        if (q (1, cx, 1, cy - 1))
        {
            cy--;
            rres.push_back('R');
        }
        else
        {
            cx--;
            rres.push_back('D');
        }
    }
    cout << "! ";
    for (int i = 0; i < N - 1; i++)
        cout << res[i];
    for (int i = N - 2; i >= 0; i--)
        cout << rres[i];
    cout << endl;
}