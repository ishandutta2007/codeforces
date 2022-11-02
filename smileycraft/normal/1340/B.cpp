
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

ll binary_string_to_number(string s){
    ll n = 0;
    for (ll i = 0; i < s.size(); ++i) n = 2 * n + (s[i] - '0');
    return n;
}

ll count_bits(ll n){
    ll c = 0;
    while (n > 0){
        c += n & 1;
        n >>= 1;
    }
    return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(13);

    vector<string> displays = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    vll numbers(10);
    for (ll i = 0; i < 10; ++i) numbers[i] = binary_string_to_number(displays[i]);

    ll n, k;
    cin >> n >> k;

    vll input(n);
    for (ll i = 0; i < n; ++i){
        string s;
        cin >> s;
        input[i] = binary_string_to_number(s);
    }

    vector<vector<bool>> possible(n + 1, vector<bool>(k + 1, false));
    possible[n][0] = true;
    for (ll i = n - 1; i >= 0; --i){
        set<ll> additions;
        for (ll j = 0; j < 10; ++j) if ((input[i] & numbers[j]) == input[i]) additions.insert(count_bits(numbers[j] & (~input[i])));
        vll adds;
        for (ll x : additions) adds.push_back(x);
        for (ll j = 0; j <= k; ++j) for (ll x : adds) if (x <= j && possible[i + 1][j - x]) possible[i][j] = true;
    }

    if (!possible[0][k]){
        cout << -1 << endl;
        return 0;
    }

    vll output(n);
    ll todo = k;
    for (ll i = 0; i < n; ++i){
        for (ll j = 9; j >= 0; --j) if ((input[i] & numbers[j]) == input[i]){
            ll cost = count_bits(numbers[j] & (~input[i]));
            if (cost <= todo && possible[i + 1][todo - cost]){
                output[i] = j;
                todo -= cost;
                break;
            }
        }
    }

    for (ll i : output) cout << i;
    cout << endl;

    return 0;
}