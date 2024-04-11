#include <iostream>
#include <cstdio>

#include <algorithm>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())

using namespace std;

int k, a, b;
vector<int> ans;
string s;/*
void brute(int x, int len)
{
    if(x == k && len == 0)
    {
        int q = ans[0] - 1, j = 0;
        forv(i, s)
        {
            cout << s[i];
            if(i == q && i != s.size() - 1)
            {
                q += ans[++j];
                cout << endl;
            }
        }
        exit(0);
    }
    else if(x < k)
    {
        for(int i = a; i <= b; i++)
        {
            ans[x] = i;
            len -= i;
            brute(x + 1, len);
            len += i;
        }
    }
}
*/
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    long long m[60][10], ans = 0;
    string s;
    cin >> s;
    bool flag = true;
    forv(i, s)
    {
        if(i > 0 && abs(s[i] - s[i - 1]) > 1)
            flag = false;
    }
    if(flag == true)
        ans--;
    forn(i, 10)
    {
        memset(m, 0, sizeof(m));
        m[0][i] = 1;
        for(int j = 1; j < s.size(); j++)
        {
            forn(k, 10)
            {
                if(m[j - 1][k] != 0)
                {
                    if((int(s[j] - '0') + k) % 2 == 0)
                    {
                        m[j][(int(s[j] - '0') + k) / 2] += m[j - 1][k];
                    }
                    else
                    {
                        m[j][(int(s[j] - '0') + k) / 2] += m[j - 1][k];
                        m[j][(int(s[j] - '0') + k) / 2 + 1] += m[j - 1][k];
                    }
                }
            }
        }
        forn(k, 10)
        {
            ans += m[s.size() - 1][k];
        }
    }
    cout << ans;
    return 0;
}