#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define what(x) cerr << #x << " is " << x << endl;

int in[100000];
int mp[4] = {0, 2, 3, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        ll x;
        cin >> x; x--;
        ll term = x / 3;
        ll sum = 0, pw = 0;
        while(sum + (1LL << pw) < term + 1) {
            sum += (1LL << pw);
            pw += 2;
        }
        term -= sum;
        ll a = (1LL << pw) + term;
        ll b = (1LL << (1 + pw));
        ll bi = 0;
        while(term > 0) {
            b |= (1LL << bi) * mp[term & 3];
            term >>= 2;
            bi += 2;
        }
        ll c = a ^ b;
        if(x % 3 == 0) cout << a << '\n';
        else if(x % 3 == 1) cout << b << '\n';
        else cout << c << "\n";
//        cout << a << " "  << b << " " << c << endl;

    }

//    for(int it = 0; it < 100; it++) {
//        for(int a = 1; a < 1000; a++) {
//            if(in[a]) continue;
//            bool found = false;
//            for(int b = a + 1; b < 1000; b++) {
//                if(in[b] || in[a ^ b]) continue;
//                found = true;
//                cout << a << " " << b << " " << (a ^ b)  << "\n";
//                in[a] = in[b] = in[a ^ b] = 1;
//                break;
//            }
//            if(found) break;
//        }
//    }

}