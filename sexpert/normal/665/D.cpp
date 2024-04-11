#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 2e6 + 10;
int pr[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int p = 2; p < MAX; p++) {
        if(!pr[p]) {
            for(int q = 2 * p; q < MAX; q += p)
                pr[q] = 1;
        }
    }

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int mx = 1;
    vector<int> res = {a[0]};
    // take as many odds as possible
    if(a[1] == 1) {
        int ptr = 1;
        while(ptr < n && a[ptr] == 1)
            ptr++;
        mx = ptr;
        res.assign(ptr, 1);
        for(int i = 0; i < n; i++) {
            if(a[i] != 1 && pr[a[i] + 1] == 0) {
                mx = ptr + 1;
                res.push_back(a[i]);
                break;
            }
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(pr[a[i] + a[j]] == 0) {
                    mx = 2;
                    res = {a[i], a[j]};
                    break;
                }
            }
        }
    }
    cout << mx << '\n';
    for(auto x : res)
        cout << x << " ";
    cout << '\n';
}