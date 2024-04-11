#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main() {
    int n, s;
    map<int, int> sell;
    map<int, int, greater<int>> buy;
    stack<pi> st;
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        char d;
        int p, q;
        cin >> d >> p >> q;
        if (d == 'B') {
            if (buy.count(p))
                buy[p] += q;
            else
                buy.insert({p, q});
        } else {
            if (sell.count(p))
                sell[p] += q;
            else
                sell.insert({p, q});
        }
    }
    
    for (int i=0; i<s && !sell.empty(); i++) {
        st.push(*sell.begin());
        sell.erase(sell.begin());
    }
    while (!st.empty()) {
        cout << "S " << st.top().first << " " << st.top().second << endl;
        st.pop();
    }
    for (int i=0; i<s && !buy.empty(); i++) {
        cout << "B " << buy.begin()->first << " " << buy.begin()->second << endl;
        buy.erase(buy.begin());
    }
    
    return 0;
}