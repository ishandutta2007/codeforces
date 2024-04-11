#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 3;

int main()
{
    long long n, a[MAXN];
    long long t, sum = 0;
    cin >> n >> t;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    long long ans = 0;
    long long tempt = t, ct = 0;
    set<int> goodIndices;
    for(int i = 0; i < n; i++)
        goodIndices.insert(i);
    vector<int> bad;
    int it = 0, ctbad = 0;
    while(true)
    {
        tempt = t;
        sum = 0;
        ct = 0;
        ctbad = 0;
        for(auto x : goodIndices)
        {
            if(tempt >= a[x])
            {
                tempt -= a[x];
                sum += a[x];
                ct++;
            }
            else
            {
                ctbad++;
                bad.push_back(x);
            }
        }
        for(int i = 0; i < ctbad; i++)
        {
            goodIndices.erase(bad[it]);
            it++;
        }
        if(sum == 0)
            break;
        ans += ct*(t/sum);
        t %= sum;
    }
    cout << ans << endl;
}