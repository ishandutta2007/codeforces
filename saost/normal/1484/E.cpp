#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FOR(i,l,r) for(int i=l; i<=r; i++)
#define FORD(i,r,l) for(int i=r; i>=l; i--)
using namespace std;
const int N = 3e5 + 5;
int n, r, h[N], b[N], Lft[N], Q[N], ok[N];
long long f[N], res = -1e15, rem[N];
vector<int> Ans;

void Enter() {
    cin >> n;
    FOR(i,1,n) cin >> h[i];
    FOR(i,1,n) cin >> b[i];
}

void update(int x, long long val) {
    for(++x; x; x-=x&-x) f[x] = max(f[x], val);
}

long long getBIT(int x) {
    long long val = -1e15;
    for(++x; x<=n+1; x+=x&-x) val = max(val, f[x]);
    return val;
}

void Process() {
    FORD(i,n,1) {
        while (r && h[i] < h[Q[r]]) {
            Lft[Q[r--]] = i+1;
        }
        Q[++r] = i;
        if (r == 1) ok[i] = true;
    }
    while (r) Lft[Q[r--]] = 1;
    fill(f, f+n+2, -1e15);
    update(0, 0);
    FOR(i,1,n) {
        long long val = getBIT(Lft[i]-1) + b[i];
        if (Lft[i] != 1) val = max(val, rem[Lft[i] - 1]);
        rem[i] = val;
        update(i, val);
        if (ok[i]) res = max(res, val);
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}