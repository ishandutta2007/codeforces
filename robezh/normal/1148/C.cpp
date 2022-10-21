#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)3e5 + 50;

int n;
int num[N];
vector<int> L, R;
vector<P> res;
int loc[N];

void change(int i, int j) {
//    if(i == j) return ;
    swap(num[i], num[j]);
    loc[num[i]] = i;
    loc[num[j]] = j;
    res.push_back({i, j});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> num[i]; num[i]--;
        loc[num[i]] = i;
    }

    for(int i = n / 2 - 1; i >= 0; i--) {
        int j = n - 1 - i;
        if(loc[i] != i) {
            if(loc[i] >= n / 2) change(loc[i], 0);
            change(loc[i], n - 1);
            change(loc[i], i);
        }
        if(loc[j] != j) {
            if(loc[j] < n / 2) change(loc[j], n - 1);
            change(loc[j], 0);
            change(loc[j], j);
        }
    }
    cout << res.size() << "\n";
    for(const auto &p : res) cout << p.first + 1 << " " << p.second + 1 << "\n";
//    for(int i = 0; i < n; i++) cout << num[i] << " ";
}