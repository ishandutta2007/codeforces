#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, m, k, res;
string s;

void Enter() {
    cin >> n >> s;
}

void Process() {
    int j = 0, id = 0, i;
    for(i=1; i<n; ++i) {
        if (s[i] < s[j] || id && s[i] == s[j]) {
            id = j = i;
        }
        else if (s[i] == s[j]) {
            --j;
            if (j < 0) break;
        }
        else break;
    }
    FOR(i, 0, id) cout << s[i];
    FORD(i, id, 0) cout << s[i];
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