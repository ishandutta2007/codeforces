#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

bool works (string s, int x)
{
    int bloc = x;
    for (int i = 0; i < x; i++)
    {
        if (s[i] == 'a')
            continue;
        else
        {
            if (bloc >= s.length()) return false;
            if (s[bloc] != s[i]) return false;
            bloc++;
        }
    }
    return bloc == s.length();
}

int main()
{
    ios_base::sync_with_stdio(0);
    string t;
    cin >> t;
    int N = t.length();
    int na = 0;
    for (int i = 0; i < N; i++)
        if (t[i] == 'a')
            na++;

    int ss = (N + na) / 2;
    if (ss * 2 == N + na && works (t, ss))
    {
        for (int i = 0; i < ss; i++)
        {
            cout << t[i];
        }
        cout << "\n";
    }
    else
        cout << ":(\n";
}