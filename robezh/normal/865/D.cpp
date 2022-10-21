#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50;

int n;
int num[N];

int main() {
    cin >> n;
    ll res = 0;
    priority_queue<int, vector<int>, greater<> > pque;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        if(!pque.empty() && pque.top() < num[i]) {
            res += num[i] - pque.top();
            pque.pop();
            pque.push(num[i]);
        }
        pque.push(num[i]);
    }
    cout << res << endl;
}