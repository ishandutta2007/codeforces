#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k,d,t;

void solve(){
    t *= 2;
    double res = 0;
    ll pd = (k % d == 0 ? 0 : d - k%d);
    //cout << "pd = " << pd << endl;
    ll onW = 2 * k, offW = pd;
    res += (t / (onW + offW)) * (k + pd);

    t -= (t / (onW + offW)) * (onW + offW);
    if(t <= onW){
        res += (double)t/2;
    }
    else{
        res += k + (double)(t-onW);
    }
    cout << fixed << setprecision(10) << res << endl;
}

int main() {
    cin >> k >> d >> t;
    solve();
    

}