#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int main() {
    int n;
    cin >> n;
    vector <int> x(n), y(n), z(n);
    for(int i = 0; i < n; i ++) cin >> x[i] >> y[i] >> z[i];
    map <int, vector<int> > mx, my;
    map <int, vector<int> > :: iterator ix, iy;
    for(int i = 0; i < n; i ++) mx[x[i]].push_back(i);
    vector <int> rx;
    for(ix = mx.begin(); ix != mx.end(); ix ++) {
        vector <int> &u = ix -> second;
        my.clear();
        for(auto i : u) my[y[i]].push_back(i);
        vector <int> ry;
        for(iy = my.begin(); iy != my.end(); iy ++) {
            vector <int> &v = iy -> second;
            sort(v.begin(), v.end(), [&](int i, int j) {return z[i] < z[j];});
            if(v.size() & 1) ry.push_back(v.back());
            for(int i = 1; i < v.size(); i += 2) cout << v[i-1]+1 << ' ' << v[i]+1 << endl;
        }
        if(ry.size() & 1) rx.push_back(ry.back());
        for(int i = 1; i < ry.size(); i += 2) cout << ry[i-1]+1 << ' ' << ry[i]+1 << endl;
    }
    for(int i = 1; i < rx.size(); i += 2) cout << rx[i-1]+1 << ' ' << rx[i]+1 << endl;
}