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
string str;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> str;
    int res = 0, cur = 0;
    for(char c : str) {
        if(c == '(') {
            if(cur < 0) res++;
            cur++;
        }
        else {
            cur--;
            if(cur < 0) res++;
        }
    }
    if(cur != 0) res = -1;
    cout << res << endl;

}