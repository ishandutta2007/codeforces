#include <bits/stdc++.h>
using namespace std;

int s, mod;

int val(pair<int, int> p)
{
    return p.first*mod + p.second;
}

string bfs()
{
    vector<int> vist(5000005);
    vector<int> prev(5000005);
    queue<int> q;
    for(int d = 1; d <= 9; d++)
    {
        pair<int, int> p = {d, d %mod}, o = {-1, -1};
        q.push(val(p));
        prev[val(p)] = 10*val(o) + d;
        vist[val(p)] = 1;
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        pair<int, int> p = {x / mod, x % mod};
        if(p.first == s && p.second == 0)
            break;
        for(int d = 0; d <= 9; d++)
        {
            pair<int, int> o = {p.first + d, (10*p.second + d)%mod};
            if(!vist[val(o)] && o.first <= s)
            {
                vist[val(o)] = 1;
                q.push(val(o));
                prev[val(o)] = 10*val(p) + d;
            }
        }
    }
    if(!vist[mod * s])
        return "-1";

    string ans = "";
    pair<int, int> p = {s, 0};
    while(p.first > 0)
    {
        ans = to_string((prev[val(p)] % 10 + 10)%10) + ans;
        int x = prev[val(p)]/10;
        p = {x / mod, x % mod};
    }
    return ans;
}

int main()
{
    cin >> mod >> s;
    cout << bfs() << endl;
}