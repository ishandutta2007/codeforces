#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)4e5 + 50;

int n;
vector<int> x;
int la;

void answer(int g = 0, int s = 0, int b = 0) {
    cout << g << " " << s << " " << b << '\n';
}

void solve() {
    x.clear();
    la = -1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int cur; cin >> cur;
        if(cur == la) x.back()++;
        else {
            x.push_back(1);
            la = cur;
        }
    }
    int g, s = 0, b = 0;
    reverse(x.begin(), x.end());
//    for(int v : x) cout << v << " ";
//    cout << endl;
    g = x.back();
    x.pop_back();
    int sum = g;
    while(s <= g) {
        if(x.empty()) {
            answer();
            return ;
        }
        s += x.back();
        x.pop_back();
    }
    while(b <= g) {
        if(x.empty()) {
            answer();
            return ;
        }
        b += x.back();
        x.pop_back();
    }
    while(!x.empty() && g + s + b + x.back() <= n / 2) {
        b += x.back();
        x.pop_back();
    }
//    cout << g << s << b << endl;
    if(g + s + b > n / 2) {
        answer();
        return ;
    }
    answer(g, s, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}