#include <bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int res = 0;
        int v0 = 0, v1 = 0;
        cin >> s;
        for(char c : s) {
            if(c == '(') v0++;
            if(c == '[') v1++;
            if(c == ')') if(v0) {res++, v0--;}
            if(c == ']') if(v1) {res++, v1--;}
        }
        cout << res << '\n';
    }
}