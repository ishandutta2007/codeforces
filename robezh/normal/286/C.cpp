#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 50;

int n;
int num[N];
int x[N];
int k;
int neg[N];
unordered_map<int, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    mp.reserve(32768);
    mp.max_load_factor(0.2);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    cin >> k;
    for(int i = 0; i < k; i++) {
        int a; cin >> a; neg[--a] = 1;
    }
    stack<int> S;
    for(int i = n - 1; i >= 0; i--) {
        if(neg[i] || mp[num[i]] == 0 || (!S.empty() && S.top() != num[i])) {
            S.push(num[i]);
            x[i] = -1;
            mp[num[i]] ++;
        }
        else {
            S.pop();
            x[i] = 1;
            mp[num[i]]--;
        }
    }
    if(!S.empty()) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) cout << x[i] * num[i] << " ";
    cout << endl;
}