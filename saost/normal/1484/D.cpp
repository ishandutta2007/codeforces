#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FOR(i,l,r) for(int i=l; i<=r; i++)
using namespace std;
const int N = 2e5 + 5;
int t, n, a[N], nxt[N], exist[N];
vector<int> Ans;

void Enter() {
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) nxt[i] = i+1;
    nxt[n] = 1;
}

void Process() {
    queue<int> Q;
    Ans.clear();
    fill(exist, exist + n + 1, 1);
    FOR(i,1,n) Q.push(i);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (!exist[u]) continue;
        int v = nxt[u];
        if (__gcd(a[u], a[v]) == 1) {
            Ans.push_back(v);
            exist[v] = 0;
            Q.push(u);
            nxt[u] = nxt[v];
        }
        if (u == v) break;
    }
    cout << Ans.size() << ' ';
    for(int v : Ans) cout << v << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        Enter();
        Process();
    }
}