#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)5e5 + 50;

int n;
string str;
int nxt[N];
ll res = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> str;
    ll csum = 0;
    for(int i = 0; i <= n; i++) nxt[i] = min(i + 1 , n);

    res = csum = (str[n - 1] == '1');
    int laone = (str[n - 1] == '1' ? n - 1 : -1);

    for(int i = n - 2; i >= 0; i--) {
        if(str[i] == '0') {
            laone = -1;
        } else {
            if(str[i + 1] == '0') {
                laone = i;
                int r = i + 1;
                while(r + 1 < n && str[r + 1] == '0') r++;
                csum += r - i + 1;
                nxt[i] = nxt[r + 1];
            } else {
                csum += nxt[laone] - i;
                nxt[laone] = nxt[nxt[laone]];
            }
        }
//        cout << i << " " << csum << endl;
        res += csum;
    }
    cout << res << '\n';


}