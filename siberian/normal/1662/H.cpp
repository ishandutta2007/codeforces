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
vector<int> get(int a)
{
    vector<int> res;
    for(int i =1;i*i<=a;++i)
    {
        if(a % i == 0) 
        {
            res.pbc(i);
            res.pbc(a/i);
        }
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin>>t;
    while(t--)
    {
        int w,l;
        cin>>w>>l;
        if(w>l) swap(w,l);
        vector<int> res;
        auto ww = get(w);
        auto l2 = get(l-2);
        res.pbc(1);
        for(int i :ww)
        {
            if((l-2) % i == 0) res.pbc(i);
        }
        for(int i :ww) if(w % i ==0 && (l-1) % i ==0 && (w-2) % i == 0) res.pbc(i);
        for(int i : l2) if((w-1) % i == 0 && l% i ==0  && (l-2) % i == 0) res.pbc(i);
        auto w1 = get(w-1);
        auto w2=get(w-2);
        for(int i :w2) if((w-2) % i == 0 && l% i==0) res.pbc(i);
        for(int i:w1) if( (w-1) % i ==0  && (l-1) % i == 0) res.pbc(i);
        sort(all(res));
        res.resize(unique(all(res)) - res.begin());
        cout<<res.size()<<' ';
        for(int i : res) cout<<i<<' ';
        cout<<'\n';
    }
    return 0;
}