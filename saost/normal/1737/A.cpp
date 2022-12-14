#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, m, k, res;
int a[N], b[N], cnt[N];
string s;

void Enter() {
    FOR(i, 'a', 'z') cnt[i] = 0;
    cin >> n >> m >> s;
    for(char c : s) ++cnt[c];
}

void Process() {
    int sz = n;
    FOR(i, 1, m) {
        int tmp = n / m;
        FOR(i, 'a', 'z') if (cnt[i] == 0 || tmp == 0) {
            cout << (char)i;
            break;
        }
        else --cnt[i], --tmp;
    }
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