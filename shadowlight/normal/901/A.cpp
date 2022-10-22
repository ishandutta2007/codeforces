#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int h;
    cin >> h;
    vector <int> a(h + 1);
    for (int i = 0; i <= h; i++) {
        cin >> a[i];
    }
    int pos = -1;
    for (int i = 0; i < h; i++) {
        if (a[i] > 1 && a[i + 1] > 1) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "perfect\n";
        return 0;
    }
    cout << "ambiguous\n";
    vector <int> gr(1, 0);
    int sum = 1;
    int v = -1, k = -1;
    for (int i = 1; i <= h; i++) {
        for (int j = 0; j < a[i]; j++) {
            gr.push_back(sum);
        }
        if (i == pos + 1) {
            v = gr.size() - 1;
            k = sum - 1;
        }
        sum += a[i];
    }
    for (int x : gr) {
        cout << x << " ";
    }
    cout << "\n";
    gr[v] = k;
    for (int x : gr) {
        cout << x << " ";
    }
}