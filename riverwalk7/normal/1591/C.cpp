#include <bits/stdc++.h>
#define MAXN 200500
using namespace std;
typedef long long ll;
int T, N, K;
int x;
vector<ll> pos, neg;
//at the beginning of the problem, check if the answer fits in a 32 bit integer, or slightly more than 2 billion. If not then you need to use 64 bit integers, or long longs
ll ans;
void solve()
{
    //remember to reset your variable every test case
    pos.clear();
    neg.clear();
    ans = 0;
    cin>>N>>K;
    ll highest_coordinate = 0;
    for(int i=0; i<N; i++)
    {
        cin>>x;
        highest_coordinate = max(highest_coordinate, (ll)(abs(x)));
        if(x > 0)
        {
            pos.push_back(x);
        }
        else
        {
            neg.push_back(-x);
        }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    for(int i=0; i<pos.size(); i++)
    {
        if((i+1) % K == (pos.size() % K))
        {
            ans += (2*pos[i]);
        }
    }
    for(int i=0; i<neg.size(); i++)
    {
        if((i+1) % K == (neg.size() % K))
        {
            ans += (2*neg[i]);
        }
    }

    ans -= highest_coordinate;
    cout<<ans<<endl;
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        solve();
    }
}