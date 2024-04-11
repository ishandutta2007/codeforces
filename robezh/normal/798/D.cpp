#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;
typedef pair<int, int> P;

int n;
P p[N];
int b[N];
vector<int> res;


int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i].first; p[i].second = i;
    }
    sort(p, p + n, greater<>());
    for(int i = 0; i < n; i++) cin >> b[i];

    int st = (n % 2 == 0 ? 2 : 1);
    for(int i = 0; i < st; i++) res.push_back(p[i].second);
    for(int i = st; i < n; i += 2) {
        int x = p[i].second, y = p[i+1].second;
        res.push_back(b[x] > b[y] ? x : y);
    }
    cout << res.size() << endl;
    for(int x : res) cout << x + 1 << " ";
    cout << endl;
}