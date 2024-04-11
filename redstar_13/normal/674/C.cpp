#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

#define NN 202020

DO s[NN], p[NN], q[NN];
DO dp[NN], f[NN];
int id[NN];

DO calc(const int &u, const DO &x) {
    return x*s[u]+f[u];
}

int multi(const int &u, const int &v, const int &w) {
    return (s[u]-s[v])*(f[w]-f[v])>(s[w]-s[v])*(f[u]-f[v])-1e-9;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    int n, k, u;
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++) {
        scanf("%d", &u);
        s[i]=s[i-1]+u;
        p[i]=p[i-1]+s[i]/u;
        q[i]=q[i-1]+1.0/u;
    }

    for (int i=1; i<=n; i++) dp[i]=p[i], f[i]=s[i]*q[i];

    for (int i=2; i<=k; i++) {
        int top=0; id[top++]=i-1;
        for (int j=i; j<=n; j++) {
            int st=0, ed=top-1;
            while (st<ed) {
                int mid=st+ed>>1;
                if (calc(id[mid], -q[j])<calc(id[mid+1], -q[j])) ed=mid;
                else st=mid+1;
            }
            dp[j]=p[j]+calc(id[st], -q[j]);
            while (top>1 && multi(id[top-2], id[top-1], j)) top--;
            id[top++]=j;
        }
        for (int j=i; j<=n; j++) f[j]=dp[j]-p[j]+s[j]*q[j];
    }

    printf("%.10lf\n", dp[n]);

    return 0;
}