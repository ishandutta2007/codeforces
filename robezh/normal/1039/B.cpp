#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, k;
bool bad = false;

bool check(ll l, ll r){
    cout << l << " " << r << endl;
    fflush(stdout);
    string str;
    cin >> str;
    if(str[0] == 'B') bad = true;
    return (str[0] == 'Y');
}

bool check_ans(ll x){
    cout << x << " " << x << endl;
    fflush(stdout);
    string str;
    cin >> str;
    if(str[0] == 'B') bad = true;
    return str[0] == 'Y';
}

ll cur = 0;

int main(){

//    ll cur = (ll)1e18;
//    ll minres = (ll)1e18, mini = 0;
//    for(int i = 0; i < 100; i++){
//        if(cur + i )
//    }

    cin >> n >> k;
    ll l = 1, r = n;
    if(l == r){
        check_ans(1);
        return 0;
    }
    while(true){
        if(bad) break;
        if(r - l < 45){
            if(check_ans(l + (rng()) % (r - l + 1))) return 0;
            r = min(n, r + k);
            l = max(1LL, l - k);
            continue;
        }
        ll mid = (l + r) / 2;
        if(check(mid + 1, r)){
            l = max(1LL, mid + 1 - k);
            r = min(n, r + k);
        }
        else{
            l = max(1LL, l - k);
            r = min(n, mid + k);
        }
    }
}