#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<P> v;
        for(int i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            ll p = 1;
            while(a % m == 0)
            {
                a /= m;
                p *= m;
            }
            if(v.size() && v.back().first == a)
            {
                v.back().second += p;
            }
            else
            {
                v.push_back(P(a, p));
            }
        }
        int k;
        cin >> k;
        vector<P> w;
        for(int i = 0; i < k; i++)
        {
            ll b;
            cin >> b;
            ll p = 1;
            while(b % m == 0)
            {
                b /= m;
                p *= m;
            }
            if(w.size() && w.back().first == b)
            {
                w.back().second += p;
            }
            else
            {
                w.push_back(P(b, p));
            }
        }
        if(v.size() != w.size())
        {
            cout << "NO" << endl;
            continue;
        }
        int l = v.size();
        bool f = true;
        for(int i = 0; i < l; i++)
        {
            if(v[i].first != w[i].first || v[i].second != w[i].second)
            {
                f = false;
            }
        }
        if(f)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}