#include <bits/stdc++.h>
using namespace std;

const int N = 2505;
typedef long long ll;

int n;
int x[N];
char op[N];
ll ssum[N], pst[N];

ll solve(const string &str) {
    n = str.length();
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) x[i/2] = str[i] - '0';
        else op[i/2] = str[i];
    }
    n = n / 2 + 1;
    ssum[n] = 0, pst[n] = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(i == n - 1 || op[i] == '+') {
            ssum[i] = ssum[i+1] + pst[i+1];
            pst[i] = x[i];
        }
        else {
            ssum[i] = ssum[i+1];
            pst[i] = pst[i + 1] * x[i];
        }
    }
    ll mx = ssum[0] + pst[0];
    ll csum = 0, cst = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            cst = x[i];
        }
        else if(op[i-1] == '+') {
            csum += cst;
            cst = x[i];
        }
        else {
            cst *= x[i];
        }


        if(i == n - 1 || op[i] == '+') continue;
        ll isum = 0, ist = 0;
        for(int j = i + 1; j < n; j++) {
            if(j == i + 1) ist = x[j];
            else if(op[j-1] == '+') isum += ist, ist = x[j];
            else ist *= x[j];

            ll psum = isum + ist;

            ll cur_res;
            if(j != n - 1) {
                if(op[j] == '+') {
                    cur_res = csum + cst * psum + ssum[j+1] + pst[j+1];
                }
                else cur_res = csum + cst * psum * pst[j+1] + ssum[j+1];
            } else {
                cur_res = csum + cst * psum;
            }
            mx = max(mx, cur_res);
        }
    }
    return mx;
}

int main() {
    string str;
    cin >> str;
    ll res1 = solve(str);
    reverse(str.begin(), str.end());
    cout << max(res1, solve(str)) << endl;

}