#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;
        map<int, ll> mpa, mpb;
        for(int i = 0; i < k; i++){
            int a;
            cin >> a;
            mpa[a]++;
        }
        for(int i = 0; i < k; i++){
            int b;
            cin >> b;
            mpb[b]++;
        }
        ll ans = k * (k - 1) / 2;
        for(auto itr = mpa.begin(); itr != mpa.end(); itr++) ans -= itr->second * (itr->second - 1) / 2;
        for(auto itr = mpb.begin(); itr != mpb.end(); itr++) ans -= itr->second * (itr->second - 1) / 2;
        cout << ans << endl;
    }
}