#include<bits/stdc++.h>
using namespace std;

const int NN = 2e5+10;

int p[NN], q[NN], f[NN];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", p+i), q[i]=0;
    int a, b, x, y;
    scanf("%d %d %d %d", &x, &a, &y, &b);
    for(int i=a; i<=n; i+=a) q[i]+=x;
    for(int i=b; i<=n; i+=b) q[i]+=y;
    int st=0, ed=n+1;
    sort(p+1, p+n+1);
    reverse(p+1, p+n+1);
    long long t;
    scanf("%I64d", &t);
    while(st+1<ed) {
        int md=st+ed>>1;
        long long tot=0;
        for(int i=1; i<=md; i++) f[i]=q[i];
        sort(f+1, f+md+1);
        reverse(f+1, f+md+1);
        for(int i=1; i<=md; i++) {
            tot+=p[i]/100*f[i];
        }
        if(tot>=t) ed=md;
        else st=md;
    }
    if(ed == n+1) ed=-1;
    printf("%d\n", ed);
}

int main() {
    //freopen("C.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}