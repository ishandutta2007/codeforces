#include <bits/stdc++.h>

#define x first
#define y second
#define pb push_back
using namespace std;
using INT = long long;
using VI = vector<int>;
using pii = pair<int, int>;

const int NN = 1000111;
int a[NN];
INT b[NN];
int n;

inline INT calc(int st, int ed, INT p) {
    INT ans = 0;
    INT now = 0;
    for(int i=st; i<ed; i++) {
        now += b[i];
        ans += min(now, p-now);
    }
    return ans;
}

inline INT calc(INT p) {
    for(int i=0; i<n; i++) b[i] = a[i] % p;
    INT ans = 0;
    for(int i=0, j=0; i<n; i=j) {
        INT now = 0;
        while(j<n and now+b[j]<p) {
            now+=b[j];
            j++;
        }
        if(now) ans += calc(i, j, p);
        now += b[j];
        b[j] = now - p;
    }
    return ans;
}

int solve() {
    cin >> n;
    INT sum = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", a+i);
        sum += a[i];
    }

    if(sum<=1) return puts("-1");
    INT ans = 1LL<<60;
    for(int i=2; (INT)i*i<=sum; i++) if(sum%i==0) {
        INT tmp = calc(i);
        while(sum%i==0) sum/=i;
        if(tmp < ans) ans = tmp ;
    }
    if(sum>1) {
        INT tmp = calc(sum);
        if(tmp < ans) ans = tmp ;
    }
    cout << ans << endl;
}

int main() {
#ifdef redstar
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif // redstar
    solve();
}