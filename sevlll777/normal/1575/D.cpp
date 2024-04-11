#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

bool is_correct(int x, string &s){
    int n = s.size();
    string now;
    while (x > 0){
        now += x % 10+'0';
        x /= 10;
    }
    reverse(now.begin(), now.end());
    bool flag = true;
    char t = '#';
    for (int q = 0; q < n; q++){
        if (s[q] == 'X' && t == '#'){
            t = now[q];
        }else if (s[q] == 'X'){
            flag &= (now[q] == t);
        }else if (s[q] != '_'){
            flag &= (now[q] == s[q]);
        }
    }
    return flag;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1){
        cout << (s[0] == '0' || s[0] == 'X' || s[0] == '_' ? 1 : 0) << endl;
        return 0;
    }
    vector<int> deg = {1};
    for (int q = 0; q < 10; q++){
        deg.push_back(deg.back()*10);
    }
    int ans = 0;
    for (int q = (n == 2 ? 25 : deg[n-1]); q < deg[n]; q += 25){
        ans += is_correct(q, s);
    }
    cout << ans << endl;
    return 0;
}