#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 305;

int n;
string str[N];

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        int cnt[3] = {0, 0, 0};
        rep(i, 0, n) {
            cin >> str[i];
            rep(j, 0, n) if(str[i][j] == 'X') cnt[(i + j) % 3]++;
        }
        int mn = 0;
        rep(i, 1, 3) if(cnt[i] < cnt[mn]) mn = i;
        rep(i, 0, n) {
            rep(j, 0, n) {
                if(str[i][j] == 'X') cout << ((i + j) % 3 == mn ? 'O' : 'X');
                else cout << '.';
            }
            cout << '\n';
        }
    }
}