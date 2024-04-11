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

int N, K;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> K >> s;
    int nr = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == ')')
            nr++;
    }

    int nl = K / 2;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == '(')
        {
            if (nl > 0)
                cout << '(';
            nl--;
        }
        else
        {
            if (nr <= K / 2)
                cout << ')';
            nr--;
        }
    }
}