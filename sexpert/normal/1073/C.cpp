#include <bits/stdc++.h>
using namespace std;

string s;
int n;
long long x, y;
vector<pair<int, int>> partials = {{0, 0}};

bool valid(int len)
{
    //cout << len << "\n________\n";
    for(int i = len; i <= n; i++)
    {
        pair<int, int> p = {partials[i].first - partials[i - len].first, partials[i].second - partials[i - len].second};
        pair<int, int> eff = {partials[n].first - p.first, partials[n].second - p.second};
        //cout << p.first << " " << p.second << "\n" << eff.first << " " << eff.second << endl << endl;
        long long nx = eff.first, ny = eff.second;
        long long diff = abs(nx - x) + abs(ny - y);
        if(len >= diff)
            return true;
    }
    return false;
}

int main()
{
    cin >> n >> s >> x >> y;
    long long lev = abs(x) + abs(y);
    if(lev > n || (lev % 2 != n % 2))
    {
        cout << -1 << endl;
        return 0;
    }
    map<char, pair<int, int>> mp;
    mp['L'] = {-1, 0};
    mp['R'] = {1, 0};
    mp['U'] = {0, 1};
    mp['D'] = {0, -1};
    pair<int, int> cur = {0, 0};
    for(int i = 0; i < n; i++)
    {
        auto p = mp[s[i]];
        cur.first += p.first;
        cur.second += p.second;
        partials.push_back(cur);
    }
    int low = 0, high = n;
    while(low != high)
    {
        int mid = (low + high)/2;
        if(valid(mid))
            high = mid;
        else
            low = mid + 1;
    }
    cout << low << endl;
}