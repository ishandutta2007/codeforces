#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <pair <int, int> > e;
    map <pair <int, int>, int> ans;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int j = -1;
        int k = -1;
        for (int i = 0; i < (int) s.size(); i++)
        {
            if (s[i] == '+')
            {
                j = i;
            }
            if (s[i] == '/')
            {
                k = i;
            }
        }
        int a = 0, b = 0, c = 0;
        for (int x = 1; x < j; x++) a = a * 10 + s[x] - '0';
        for (int x = j + 1; x + 1 < k; x++) b = b * 10 + s[x] - '0';
        for (int x = k + 1; x < (int) s.size(); x++) c = c * 10 + s[x] - '0';
        a += b;
        int g = __gcd(a, c);
        a /= g;
        c /= g;
        e.push_back({a, c});
        ans[{a, c}]++;
    }
    for (auto c : e)
    {
        cout << ans[c] << ' ';
    }
    cout << '\n';
}