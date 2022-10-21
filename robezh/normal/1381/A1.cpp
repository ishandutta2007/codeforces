#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
string s, t;
string s1;
vi res;

void change(int pos) {
    res.push_back(pos);
//    for(int i = 0; i < pos; i++) s1[i] = (s1[i] == '0' ? '1' : '0');
//    reverse(s1.begin(), s1.begin() + pos);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        cin >> s >> t;
//        s1 = s;
        int l = 0, r = n - 1;
        vi idx;
        while(l <= r) {
            idx.push_back(l);
            if(l < r) idx.push_back(r);
            l++, r--;
        }
        int cnt = 0;
        res.clear();
        for(int i : idx) {
            if(((s[i] - '0') ^ (cnt & 1)) == (t[n - 1 - cnt] - '0')) {
                change(1);
            }
            change(n - cnt);
            cnt++;
        }
        cout << sz(res) << ' ';
        for(int len : res) cout << len << " ";
        cout << '\n';
//        cout << t << " " << s1 << endl;
    }

}