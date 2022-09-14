#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <ctime>
#include <set>
#include <map>
         
using namespace std;
         
typedef long long ll;
typedef long double ld;
const ll MSIZE = 200000;
const ll INF = 1e18;
const ld EPS = 1e-9;
const int alp = 26;

char make_up(char c){
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    else
        return c;
}

void transform(string& s){
    for (int i = 0; i < s.length(); ++i){
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = make_up(s[i]);
        if (s[i] == 'O')
            s[i] = '0';
        else if (s[i] == 'I' || s[i] == 'L')
            s[i] = '1';
    }
}

void solve(){
    string s;
    cin >> s;
    transform(s);
    int n;
    cin >> n;
    map<string, bool> mp;
    for (int i = 0; i < n; ++i){
        string t;
        cin >> t;
        transform(t);
        if (s == t){
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    //freopen("scrivener.in", "r", stdin);
    //freopen("scrivener.out", "w", stdout);
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    solve();
    //cerr << '\n' << fixed << setprecision(6) << ld(clock()) / CLOCKS_PER_SEC;
    return 0;
}