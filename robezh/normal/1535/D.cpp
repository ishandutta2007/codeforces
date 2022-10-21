#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)6e5 + 50;

int k;
string str;
int sub[N];

void update(int x) {
    if(str[x] == '0') sub[x] = sub[2 * x + 2];
    else if(str[x] == '1') sub[x] = sub[2 * x + 1];
    else sub[x] = sub[2 * x + 2] + sub[2 * x + 1];
}

void build(int x, int l, int r) {
    if(l == r) {
        sub[x] = 1;
        return ;
    }
    int mid = (l + r) / 2;

    build(2 * x + 1, l, mid);
    build(2 * x + 2, mid + 1, r);
    update(x);

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    cin >> str;
    reverse(all(str));
    build(0, 0, (1 << k) - 1);
    int q;
//    cout << sub[0] << endl;
    cin >> q;
    while(q--) {
        int p; char c;
        cin >> p >> c; p--;
        p = (1 << k) - 2 - p;
        str[p] = c;
        while(p) {
            update(p);
            p = (p - 1) / 2;
        }
//        build(0, 0, (1 << k) - 1);

        update(0);
        cout << sub[0] << '\n';
    }

}