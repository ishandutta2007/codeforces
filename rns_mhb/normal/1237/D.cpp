#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int main() {
    int n;
    cin >> n;
    int m = 3*n;
    vector <pii> v(m);
    for(int i = 0; i < n; i ++) cin >> v[i].first, v[i+n].first = v[i+2*n].first = v[i].first;
    for(int i = 0; i < m; i ++) v[i].second = i;
    sort(v.begin(), v.end());
    int k = 0;
    vector <int> nxt(m);
    set <int> s;
    for(int i = 0; i < m; i ++) {
        int down = v[i].first + 1 >> 1;
        while(k < m && v[k].first < down) {
            s.insert(v[k].second);
            k ++;
        }
        set <int> :: iterator it = s.lower_bound(v[i].second);
        nxt[v[i].second] = (it == s.end() ? m : *it);
    }
    for(int i = m-2; i >= 0; i --) nxt[i] = min(nxt[i], nxt[i+1]);
    for(int i = 0; i < n; i ++) cout << (nxt[i]==m ? -1 : nxt[i]-i) << ' ';
    cout << endl;
}