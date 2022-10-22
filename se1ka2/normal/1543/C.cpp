#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;

double rec(ll c, ll m, ll p, ll v, map<PP, double> &mp){
    if(mp.count(PP(P(c, m), p))) return mp[PP(P(c, m), p)];
    double res = p / 1000000000000000000.0;
    if(c != 0){
        ll d = min(v, c);
        if(m != 0){
            res += (rec(c - d, m + d / 2, p + d / 2, v, mp) + 1) * c / 1000000000000000000.0;
        }
        else{
            res += (rec(c - d, 0, p + d, v, mp) + 1) * c / 1000000000000000000.0;
        }
    }
    if(m != 0){
        ll d = min(v, m);
        if(c != 0){
            res += (rec(c + d / 2, m - d, p + d / 2, v, mp) + 1) * m / 1000000000000000000.0;
        }
        else{
            res += (rec(0, m - d, p + d, v, mp) + 1) * m / 1000000000000000000.0;
        }
    }
    return mp[PP(P(c, m), p)] = res;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        double c_, m_, p_, v_;
        cin >> c_ >> m_ >> p_ >> v_;
        ll c = round(c_ * 1000000000000000000);
        ll m = round(m_ * 1000000000000000000);
        ll p = round(p_ * 1000000000000000000);
        ll v = round(v_ * 1000000000000000000);
        map<PP, double> mp;
        cout << fixed << setprecision(15) << rec(c, m, p, v, mp) << endl;
    }
}