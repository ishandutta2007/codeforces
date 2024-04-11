#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s1;
    string s2;
    cin>>s1>>s2;
    int cur = 0;
    string fstr1;
    for (auto x: s1) {
        if (x == 'B') {
            cur++;
        } else {
            if (fstr1.size() != 0 && fstr1.back() == x) {
                fstr1.pop_back();
            } else {
                fstr1.push_back(x);
            }
        }
    }
    string fstr2;
    for (auto x: s2) {
        if (x == 'B') {
            cur--;
        } else {
            if (fstr2.size() != 0 && fstr2.back() == x) {
                fstr2.pop_back();
            } else {
                fstr2.push_back(x);
            }
        }
    }
    if (cur%2 !=0 || fstr1 != fstr2) {
        cout<<"NO\n";
    } else {
        cout<<"YES\n";
    }
}

int main() {
    int tc;cin>>tc;
    for (int i= 0; i < tc; i++) {

        solve();
    }
    

}