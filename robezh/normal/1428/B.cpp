#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> str;
        map<char, int> cnt;
        for(char c : str) cnt[c]++;
        int res1 = 0, res2 = 0;
        for(int i = 0; i < n; i++) {
            if(str[i] == '>' && str[(i + 1) % n] == '>') res2++;
            if(str[i] == '<' && str[(i + 1) % n] == '<') res2++;
            if(str[i] == '>' && str[(i + 1) % n] == '<') res1++;
            if(str[i] == '<' && str[(i + 1) % n] == '>') res1++;
        }
        cout << n - (cnt['>'] && cnt['<'] ? res1 + res2 : res1) << '\n';

    }

}