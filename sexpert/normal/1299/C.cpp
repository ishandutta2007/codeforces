#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v)
        cin >> x;
    ll cc = 0, cs = 1000000000;
    vector<double> ans;
    vector<ii> caideogithenvmdava;
    for(auto x : v) {
        caideogithenvmdava.push_back({x, 1});
        while(true) {
            if(caideogithenvmdava.size() < 2)
                break;
            auto b1 = caideogithenvmdava.back();
            auto b2 = caideogithenvmdava[caideogithenvmdava.size() - 2];
            if((b1.first + b2.first)*b2.second < b2.first*(b1.second + b2.second)) {
                caideogithenvmdava.pop_back();
                caideogithenvmdava[caideogithenvmdava.size() - 1] = {b1.first + b2.first, b1.second + b2.second};
                continue;
            }
            break;
        }
    }
    for(auto b : caideogithenvmdava) {
        for(int i = 0; i < b.second; i++) {
            cout << fixed << setprecision(10) << ((double)b.first / (double)b.second) << '\n';
        }
    }
}