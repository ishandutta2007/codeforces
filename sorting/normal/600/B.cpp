#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;

    sort(all(a));
    for(int i = 0; i < m; ++i)
        cout << upper_bound(all(a), b[i]) - a.begin() << " ";
    cout << "\n";
}