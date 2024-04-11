#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
#define double long double
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;

    vector <int> p(n), t(n);
    for (int i = 0; i < n; ++i) 
        cin >> p[i];

    for (int i = 0; i < n; ++i)
        cin >> t[i];

    map <ii, vector <int> > d;
    for (int i = 0; i < n; ++i) {
        int a = p[i], b = t[i];
        int dv = __gcd(a, b);
        a /= dv; b /= dv;
        d[mp(a,b)].app(i);
    }   
    
    vector <int> lf(n), b(n);

    vector <ii> ko;
    for (auto e : d)
        ko.app(e.f);

    auto comp_ko = [](ii a, ii b) {
        return a.f * b.s > b.f * a.s;
    };

    sort(all(ko), comp_ko);

    int cur = 0;
    for (auto key : ko) {
        int sumt = 0;
        for (int i : d[key])
            sumt += t[i];
        for (int i : d[key]) {
            b[i] = sumt;            
            lf[i] = cur;
        }
        cur += sumt;
    }   

    double T = 0;
    for (auto e : t)
        T += e;

    auto comp = [&] (int i, int j) {
        return p[i] < p[j];
    };
    vector <int> ord;
    for (int i = 0; i < n; ++i)
        ord.app(i);
    sort(all(ord), comp);

    auto check = [&] (double c) {
        int ptr = 0;
        double mx = 0;
        for (int i : ord) {
            while (ptr < n && p[ord[ptr]] < p[i]) {
                int num = ord[ptr];
                mx = max(mx, p[num] * (1 - c * (lf[num] + t[num]) / T));
                ++ptr;    
            }
            double mn = p[i] * (1 - c * (lf[i] + b[i]) / T);

            //cout << "time : " << lf[i] + b[i] << endl;
            //cout << i << " : " << mn << endl;

            if (mn < mx)
                return true;
        }           
        return false;
    };          

    /*
    cout << check(0.7) << endl;
    exit(0);
    */

    double l = 0, r = 1;
    for (int it = 0; it < 100; ++it) {
        double m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m;
    }   
    cout.precision(20);
    cout << r << endl;
}