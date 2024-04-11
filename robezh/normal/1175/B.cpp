#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ld MX = (ld)((1LL << 32) - 1);

stack<ld> S, mul;

int main() {
    int n;
    S.push(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if(str[0] == 'a') S.top() += 1;
        else if(str[0] == 'f') {
            int x; cin >> x;
            S.push(0);
            mul.push(x);
        }
        else {
            ld cur = S.top();
            S.pop();
            S.top() += mul.top() * cur;
            mul.pop();
        }
    }
    if(S.top() > MX) cout << "OVERFLOW!!!" << endl;
    else cout << (ll)S.top() << endl;
}