#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int query(const vector<int> &v){
    cout << "? ";
    for(int x: v)
        cout << x;
    cout << endl;

    int res;
    cin >> res;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> e(m);
    for(int i = 0; i < m; ++i){
        vector<int> v(m, 0);
        v[i] = true;
        e[i] = query(v);
    }

    vector<int> p(m);
    iota(all(p), 0);

    sort(all(p), [&](int l, int r){
        return e[l] < e[r];
    });

    vector<int> curr(m, 0);
    int prev = 0;
    for(int i = 0; i < m; ++i){
        curr[p[i]] = true;
        int new_res = query(curr);
        if(new_res == prev + e[p[i]]){
            prev = new_res;
        }
        else{
            curr[p[i]] = false;
        }
    }

    cout << "! " << prev << endl;
}