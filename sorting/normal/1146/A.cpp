#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int cnt_a = 0;
    for(char c: s)
        cnt_a += 'a' == c;

    cout << min(cnt_a * 2 - 1, (int)s.size()) << "\n";
}