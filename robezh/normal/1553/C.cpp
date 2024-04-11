#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string str;

int rd(int tp) {
    int w[2] = {0, 0};
    int rem[2] = {5, 5};
    rep(i, 0, 10) {
        if(str[i] != '?') w[i % 2] += str[i] - '0';
        else {
            if(i % 2 == tp) w[i % 2]++;
        }
        rem[i % 2]--;
        if(w[tp] > w[!tp] + rem[!tp]) return i + 1;
    }
    return 10;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> str;
        cout << min(rd(0), rd(1)) << '\n';
    }


}