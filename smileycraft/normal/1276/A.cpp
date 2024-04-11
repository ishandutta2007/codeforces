
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

int main(){
    ll T;
    cin >> T;
    while (--T >= 0){
        string bad1 = "one", bad2 = "two";
        string s;
        cin >> s;
        ll i = 0, j = 0;
        vll retval;
        for (ll k = 0; k < s.size(); ++k){
            char c = s[k];
            if (c == bad1[i]) ++i;
            else if (c == bad1[0]) i = 1;
            else i = 0;
            if (c == bad2[j]) ++j;
            else if (c == bad2[0]) j = 1;
            else j = 0;
            if (i == bad1.size() || j == bad2.size()){
                if (k + 1 < s.size() && s[k] == s[k + 1]) retval.push_back(k);
                else retval.push_back(k + 1);
                i = j = 0;
            }
        }
        cout << retval.size() << endl;
        if (!retval.empty()) cout << retval[0];
        for (ll k = 1; k < retval.size(); ++k) cout << ' ' << retval[k];
        cout << endl;
    }
    return 0;
}