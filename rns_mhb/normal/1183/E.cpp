#include<bits/stdc++.h>
using namespace std;

vector <string> sub(vector <string> v) {
    vector <string> w;
    for(int i = 0; i < v.size(); i ++) {
        int n = v[i].size();
        for(int j = 0; j < n; j ++) w.push_back(v[i].substr(0, j)+v[i].substr(j+1, n));
    }
    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());
    return w;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector <string> v(1), w;
    cin >> v[0];
    for(int c = 0, cost = 0; c <= n; c ++) {
        if(v.size() >= k) {
            cost += c * k;
            printf("%d\n", cost);
            return 0;
        }
        if(c == n) {
            puts("-1");
            return 0;
        }
        k -= v.size();
        cost += c * v.size();
        w = sub(v);
        swap(v, w);
    }
}