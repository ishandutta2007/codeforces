#include <bits/stdc++.h>
using namespace std;

int n;
string l, r;

string add(string s) {
    reverse(s.begin(), s.end());
    string ans;
    int carry = 1;
    for(int i = 0; i < s.size(); i++) {
        if(!carry)
            ans += s[i];
        else {
            if(s[i] == '1')
                ans += '0';
            else {
                ans += '1';
                carry = 0;
            }
        }
    }
    if(carry)
        ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
}

bool cmp(string l, string r) {
    for(int i = 0; i < l.size(); i++) {
        if(r[i] != l[i])
            return r[i] > l[i];
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l >> r;

    if(l == r) {
        cout << l << '\n';
        return 0;
    }

    if(l[0] == '0' && r[0] == '1') {
        for(int i = 0; i < n; i++)
            cout << "1";
        cout << '\n';
        return 0;
    }

    if(r.back() == '0') {
        string l2 = add(add(l));
        if(cmp(l2, r)) {
            for(int i = 0; i < n - 1; i++)
                cout << r[i];
            cout << "1\n";
            return 0;
        }
    }

    cout << r << '\n';
}