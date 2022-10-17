#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 100;

int N;
int val[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;
    vector<bool> used(N); 

    for (int i = 0; i < N; i++) {
        cin >> val[i];
        val[i]--;

        if (val[i] < N) used[val[i]] = true;
    }

    vector<int> unused;
    for (int i = 0; i < N; i++)
        if (!used[i])
            unused.push_back(i);

    vector<int> done(N);

    for (int i = 0; i < N; i++) {
        if (val[i] < N && !done[val[i]]) {
            done[val[i]] = true;
            cout << val[i] + 1 << " ";
        }
        else {
            cout << unused.back() + 1 << " ";
            unused.pop_back();
        }
    }

    cout << "\n";
}