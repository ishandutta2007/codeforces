
#include <iostream>
using namespace std;
const int N = 2e5+5, M = 1e7+5;
int t, n, k, prv[N], a[N], note[N], Left[N][25], val[N][25];
int f[M], prime[M], avail[M], pos[M];
 
void eratos() {
    int NN = 1e7, cnt = 0;
    f[1] = 1;
    for(int i=2; i<=NN; i++) {
        if (!f[i]) f[i] = prime[++cnt] = i;
        int j = 1;
        while (j<=cnt && prime[j] <= f[i] && prime[j]*i <= NN) {
            f[prime[j]*i] = prime[j];
            j++;
        }
    }
}
 
void Enter() {
    cin >> n >> k;
    int x;
    for(int i=1; i<=n; i++) {
        cin >> x;
        int d = 0, v = 1, nxt = 1;
        while (f[x] > 1) {
            if (nxt == f[x]) nxt = 1; else {
                v *= nxt;
                nxt = f[x];
            }
            x /= f[x];
        }
        v *= nxt;
        a[i] = v;
    }
}
 
void Init() {
    fill(prv+1, prv+n+1, 0);
    for(int i=1; i<=n; i++) {
        int v = a[i];
        if (avail[v] != t) avail[v] = t, pos[v] = t;
            else prv[i] = pos[v];
        avail[v] = t;
        pos[v] = i;
    }
    ///
    fill(note+1, note+n+1, 0);
    for(int j=0; j<=k; j++) {
        int d = j, now = 0;
        for(int i=1; i<=n; i++) {
            if (prv[i] > now) {
                note[prv[i]] = j+1;
                if (d) --d;
                else {
                    ++now;
                    while (note[now] != j+1) ++now;
                }
            }
            Left[i][j] = now;
        }
    }
}
 
void Process() {
    for(int i=1; i<=n; i++) val[i][0] = val[Left[i][0]][0] + 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            val[i][j] = 1e9;
            for(int w=0; w<=j; w++) {
                val[i][j] = min(val[i][j], val[Left[i][w]][j-w] + 1);
            }
        }
    }
    cout << val[n][k] << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    eratos();
    do {
        Enter();
        Init();
        Process();
    } while (--t);
}