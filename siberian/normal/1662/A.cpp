#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int>> a(n);
        for(int i=0 ; i< n;++i) cin>>a[i].first>>a[i].second;
        vector<int> mx(11,-1e9);
        for(int  i =0 ; i< n;++i) mx[a[i].second]=max(mx[a[i].second], a[i].first);
            bool ok =0;
        for(int i=1;i<=10;++i) if( mx[i] <0) ok=1;
        if(ok) cout<<"MOREPROBLEMS\n";
        else
        {
            int ans=0;
            for(int i=1;i<=10;++i) ans += mx[i];
            cout<<ans<<'\n';
        }
    }
    return 0;
}