#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define MAXN 100100
using namespace std;
typedef long long ll;
int N, D, M; ll x;
vector<ll> s, t;
ll prefix[MAXN];
ll ans, cur, sum;
int main()
{
    cin>>N>>D>>M;
    for(int i=0; i<N; i++)
    {
        cin>>x;
        if(x <= M)
        {
            s.push_back(x);
        }
        else
        {
            t.push_back(x);
        }
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    for(int i=0; i<s.size(); i++)
    {
        prefix[i+1] = prefix[i] + s[i];
    }
    for(int i=s.size()+1; i<=N; i++)
    {
        prefix[i] = prefix[i-1];
    }
    ans = prefix[N];
    cur = N-1;
    for(int i=0; cur >= 0 && i < t.size(); i++)
    {
        sum += t[i];
        ans = max(ans, sum + prefix[cur]);
        cur -= (D+1);
    }
    cout<<ans<<endl;
}