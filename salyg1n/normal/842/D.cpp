#pragma GCC optimize("O3")
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <cassert>
#include <random>
#include <cstring>
#include <climits>
#include <time.h>
#include <chrono>
#include <fstream>

#define int int_fast32_t

using namespace std;
string mask = "0000000000000000000";
struct Node
{
    int nx[2];
    int IsTerm, cnt;
    Node()
    {
        nx[0] = nx[1] = -1;
        IsTerm = cnt = 0;
    }
};

Node p[(int)1e6];
int sz = 1;

void add_string(string& s)
{
    int v = 0;
    for (auto c : s)
    {
        p[v].cnt++;
        if (p[v].nx[c - '0'] == -1)
        {
            p[v].nx[c - '0'] = sz++;
        }
        v = p[v].nx[c - '0'];
    }
    p[v].IsTerm++;
    p[v].cnt++;
}

void get_mex(int v, int i, int all, string& res)
{
    //cout << res << " " << i << " " << all << '\n';
    if (i == 19)
    {
        return;
    }
    if (mask[i] == '0')
    {
        for (int j = 0; j <= 1; ++j)
        {
            if (p[v].nx[j] == -1)
            {
                p[v].nx[j] = sz++;
                res += char('0' + j);
                get_mex(p[v].nx[j], i + 1, all >> 1, res);
                return;
            }
            if (p[p[v].nx[j]].cnt != (all >> 1))
            {
                res += char('0' + j);
                get_mex(p[v].nx[j], i + 1, all >> 1, res);
                return;
            }
        }
    }
    else
    {
        for (int j = 1; j >= 0; --j)
        {
            if (p[v].nx[j] == -1)
            {
                p[v].nx[j] = sz++;
                res += to_string(j ^ 1);
                get_mex(p[v].nx[j], i + 1, all >> 1, res);
                return;
            }
            if (p[p[v].nx[j]].cnt != (all >> 1))
            {
                res += to_string(j ^ 1);
                get_mex(p[v].nx[j], i + 1, all >> 1, res);
                return;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> st;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        string s(19, '0');
        for (int i = 0; i < 19; ++i)
            if (a & (1 << i))
                s[19 - i - 1] = '1';
        st.push_back(s);
    }
    stable_sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    for (auto s : st)
    {
        add_string(s);
    }
    for (int i = 0; i < m; ++i)
    {
        int a;
        cin >> a;
        string s(19, '0');
        for (int i = 0; i < 19; ++i)
            if (a & (1 << i))
                s[19 - i - 1] = '1';
        for (int j = 0; j < 19; ++j)
        {
            mask[j] = (((mask[j] - '0') + (s[j] - '0')) % 2 + '0');
        }
        //cout << mask << '\n';
        string res = "";
        get_mex(0, 0, 524288, res);
        reverse(res.begin(), res.end());
        int ans = 0, now = 1;
        for (int j = 0; j < 19; ++j)
        {
            ans += (res[j] - '0') * now;
            now <<= 1;
        }
        cout << ans << '\n';
    }
    return 0;
}