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

int N;
int m[8];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 0; i < 8; i++)
        m[i] = 1e6;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int c;
        string s;
        cin >> c >> s;
        int cc = 0;
        for (int j = 0; j < s.length(); j++)
            cc += (1 << (s[j] - 'A'));
        m[cc] = min (m[cc], c);
    }

    int mans = 1e9;
    for (int i = 0; i < 256; i++)
    {
        int b = 0, cc = 0;
        for (int j = 0; j < 8; j++)
        {
            if (i & (1 << j))
            {
                b |= j;
                cc += m[j];
            }
        }
        if (b == 7)
            mans = min (mans, cc);
    }
    if (mans >= 1e6)
        cout << "-1\n";
    else
        cout << mans << "\n";
}