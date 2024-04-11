#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAXN 300100
using namespace std;
typedef long long ll;
ll N, M;
ll w, c;
vector<ll> x[4];
ll prefix[4][MAXN];
ll cur, ans, best;
bool comp(ll a, ll b)
{
    return a > b;
}
ll test(ll s, ll t)
{
    if((s >= (2*t+2)) && ((prefix[2][t] + prefix[1][s-2*t]) < (prefix[2][t+1] + prefix[1][s-2*t-2])))
    {
        return true;
    }
    return false;
}
ll solve(ll s)
{
    int lbound = 0;
    int hbound = s/2;
    int avg = 0;
    while(lbound != hbound)
    {
        avg = (lbound + hbound)/2;
        if(test(s, avg))
        {
            lbound = avg + 1;
        }
        else
        {
            hbound = avg;
        }
    }
    return (prefix[2][lbound] + prefix[1][s-2*lbound]);
}
int main()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        cin>>w>>c;
        x[w].push_back(c);
    }
    for(int i=1; i<=3; i++)
    {
        sort(x[i].begin(), x[i].end(), comp);
    }
    for(int i=1; i<4; i++)
    {
        for(int j=1; j<=x[i].size(); j++)
        {
            prefix[i][j] = prefix[i][j-1] + x[i][j-1];
        }
        for(int j=x[i].size() + 1; j<=M; j++)
        {
            prefix[i][j] = prefix[i][j-1];
        }
    }
    for(int i=0; i<=x[3].size(); i++)
    {
        cur = M-3*i;
        ans = prefix[3][i];
        ans += solve(cur);
        if(cur >= 0)
        {
            best = max(best, ans);
        }
    }
    cout<<best<<endl;
}