#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 20) + 50, INF = (int)1e9;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

int h, g;
int a[2 * N];
int mx[2 * N];
int ht[2 * N];

void f(int i) {
    int left = 2 * i, right = 2 * i + 1;
    if (a[left] == 0 && a[right] == 0) {
        a[i] = 0;
    } else {
        if(a[left] > a[right]) {
            a[i] = a[left];
            f(left);
        } else {
            a[i] = a[right];
            f(right);
        }
        if(a[left] == 0 && a[right] == 0) mx[i] = ht[i];
        else mx[i] = a[left] > a[right] ? mx[left] : mx[right];
    }
}


ll sum = 0;
vi res;
void dfs(int i) {
    while(mx[i] > g) {
        res.push_back(i);
        sum -= a[i];
        f(i);
    }
    if(a[2 * i] != 0) dfs(2 * i);
    if(a[2 * i + 1] != 0) dfs(2 * i + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    for(int i = 1; i < (1 << 20); i++) ht[i] = ht[i / 2] + 1;
    cin >> T;
    while(T--) {
        cin >> h >> g;
        sum = 0; res.clear();
        for(int i = 1; i < (1 << h); i++) {
            cin >> a[i], sum += a[i];
        }
        fill(mx, mx + (1 << h), h);
        dfs(1);
        cout << sum << "\n";
        for(int x : res) cout << x << ' ';
        cout << '\n';
        for(int i = 1; i < 2 * (1 << h); i++) a[i] = 0;
        for(int i = 1; i < 2 * (1 << h); i++) mx[i] = 0;
    }

}