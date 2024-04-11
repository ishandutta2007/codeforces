/*************************************************************************
 > File Name: zhizhang.cpp
 # Author: RUSH_D_CAT
 # 
 > Created Time: Thu Nov  3 08:22:19 2016
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
const int NICO = 300000+10;
const int MAKI = 300000+10;
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll s[NICO], t[NICO];
ll min(ll x, ll y){return x<y?x:y;}
struct cmp
{
    bool operator() (ll &a, ll &b)
    {
        return a>b;
    }
};
priority_queue<ll,vector<ll>,cmp> q;
priority_queue<pii> p;
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> s[i] >> t[i];
        if(i>=2)
        {
            if(s[i] > s[1])
            {
                q.push(t[i] - s[i] + 1);
            } else {
                p.push(make_pair(s[i], t[i]));
            }
        }
    }
    ll res = q.size();
    while(!q.empty() && q.top()<=s[1])
    {
        //cout << q.top() << endl;
        s[1] -= q.top();
        q.pop();
        while(!p.empty() && p.top().first > s[1])
        {
            q.push(p.top().second - p.top().first + 1);
            p.pop();
        }
        res = min(res, q.size());
    }
    cout << res + 1 << endl;
}