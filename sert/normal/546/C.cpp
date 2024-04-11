#include <bits/stdc++.h>

using namespace std;

set <pair<queue<int>, queue<int> > > s;
queue<int> b1, b2;
int n, k1, k2, x, st;

void outq(queue<int> q) {
    queue<int> q2 = q;
    while (!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << "\n";
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        cin >> x;
        b1.push(x);
    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        cin >> x;
        b2.push(x);
    }

    for (int iq = 0; true; iq++) {
        if (s.find(make_pair(b1, b2)) != s.end()) {
            cout << "-1";
            return 0;
        }
        s.insert(make_pair(b1, b2));
        if (b1.empty()) {
            cout << iq << " 2\n";
            return 0;
        }
        if (b2.empty()) {
            cout << iq << " 1\n";
            return 0;
        }
        if (b1.front() > b2.front()) {
            b1.push(b2.front());
            b1.push(b1.front());
        } else {
            b2.push(b1.front());
            b2.push(b2.front());
        }
        b1.pop();
        b2.pop();
        //outq(b2);
    }

    return 0;
}