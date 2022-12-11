#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define FOR(a, b) for (int a = 0; a < b; a++)
#define clr(a) memset(a, 0, sizeof(a))
#define ll long long
//define _in_s(a, b) (((a) < h)&&((a) >= 0)&&((b) < w)&&((b) >= 0))
//const ll INF = (ll)1000000000 * (ll)1000000000;
const int INF = 1000000000;


int main()
{
    //freopen("b.in", "r", stdin);
    //freopen("b.out", "w", stdout);
    int m[3][3];
    clr(m);
    FOR(i, 3)
    {
        char c1, c2, c3;
        scanf(" %c%c%c ", &c1, &c2, &c3);
        if (c2 == '>') swap(c1, c3);
        m[c1 - 'A'][c3 - 'A'] = 1;
    }
    if ((m[0][1] == 1) && (m[1][2] == 1) && (m[2][0] == 1))
    {
                cout << "Impossible";
                return 0;
    }
    if ((m[0][2] == 1) && (m[2][1] == 1) && (m[1][0] == 1))
    {
                cout << "Impossible";
                return 0;
    }
    if ((m[1][0] == 1) && (m[0][2] == 1) && (m[2][1] == 1))
    {
                cout << "Impossible";
                return 0;
    }
    if ((m[2][0] == 1) && (m[0][1] == 1) && (m[1][2] == 1))
    {
                cout << "Impossible";
                return 0;
    }
    if ((m[1][2] == 1 )&& (m[2][0] == 1) && (m[0][1] == 1))
    {
                cout << "Impossible";
                return 0;
    }
    if ((m[2][1] == 1 )&& (m[1][0] == 1 )&& (m[0][2] == 1))
    {
                cout << "Impossible";
                return 0;
    }


    /*
    FOR(i, 3)
        FOR(j, 3)
            if (i != j && m[i][j] == 1 && m[j][i] == 1)
            {
                cout << "Impossible";
                return 0;
            }*/
    string s = "A";
    for (int i = 1; i < 3; i++)
        if (m[0][i] == 1)
        s += (char)i + 'A';
        else s = (char)(i + 'A') + s;
    if (s[0] != 'A' && s[2] != 'A')
    {
        cout << s;
        return 0;
    }
    if (s[0] == 'A')
    {
        if (m[2][1] == 1) swap(s[1], s[2]);
    }
    if (s[2] == 'A')
    {
        if (m[2][1] == 0) swap(s[0], s[1]);
    }
    cout << s;
    return 0;

    return 0;
}