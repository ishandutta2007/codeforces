#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2048;

int N, X;

int type[MAXN];
int height[MAXN];
int mass[MAXN];

int order[MAXN];

int go(int st) {
    int ans = 0;
    int strong = X;
    int idx = 0;

    priority_queue<int> t1, t2;

    while (true) {
        while (idx < N && height[order[idx]] <= strong) {
            if (type[order[idx]]) {
                t2.push(mass[order[idx]]);
            } else {
                t1.push(mass[order[idx]]);
            }
            idx++;
        }

        if (st) {
            if (t2.empty()) break;
            strong += t2.top();
            t2.pop();
        } else {
            if (t1.empty()) break;
            strong += t1.top();
            t1.pop();
        }
        
        st = !st;
        ans++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> X;
    
    for (int i = 0; i < N; i++) {
        cin >> type[i] >> height[i] >> mass[i];
        order[i] = i;
    }

    sort(order, order + N, [](int i, int j) {
        return height[i] < height[j];
    });

    cout << max(go(0), go(1)) << "\n";
}