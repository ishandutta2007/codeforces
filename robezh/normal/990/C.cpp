#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 500;

int n;
string s[N];
ll lft[N], rgt[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        int dif = 0;
        for(char c : s[i]){
            if(c == '(') dif++;
            else dif--;
            if(dif < 0) break;
        }
        if(dif >= 0) lft[dif] ++;
        reverse(s[i].begin(), s[i].end());
        dif = 0;
        for(char c : s[i]){
            if(c == ')') dif++;
            else dif--;
            if(dif < 0) break;
        }
        if(dif >= 0) rgt[dif] ++;
    }

    ll res = 0;
    for(int i = 0; i < N; i++) res += 1LL * lft[i] * rgt[i];
    //res += 1LL * (lft[0] / 2) * (rgt[0] / 2);
    //cout << lft[1] << " " << rgt[1] << endl;
    cout << res << endl;
}