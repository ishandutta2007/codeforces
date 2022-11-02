#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

const int NN = 101010;

int a[NN], b[NN], c[NN];
INT X[NN], Y[NN], Z[NN];
int I[NN], id[NN], ID[NN];
int vst[NN], flag;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    int n, k;
    cin>>n>>k;
    for (int i=1; i<=n; i++) scanf("%d%d%d", a+i, b+i, c+i), c[i]=-c[i];

    for (int i=1; i<=n; i++) id[i]=i;

    function<INT(INT,INT)> gcd=[&](INT a, INT b) {
        if (b==0) return a;
        return gcd(b, a%b);
    };
    
    auto cmp=[](int u, int v) {
        if (X[u]!=X[v]) return X[u]<X[v];
        if (Y[u]!=Y[v]) return Y[u]<Y[v];
        return Z[u]<Z[v];
    };
    
    vector<pii> ans;

    while (n && ans.size()<=k) {
        int cur=0;
        for (int i=2; i<=n; i++) {
            INT A=(INT)a[id[1]]*(INT)b[id[i]]-(INT)a[id[i]]*b[id[1]];
            if (!A) continue;
            INT B=(INT)c[id[1]]*(INT)b[id[i]]-(INT)c[id[i]]*b[id[1]];
            INT C=(INT)a[id[1]]*(INT)c[id[i]]-(INT)a[id[i]]*c[id[1]];
            INT g=gcd(A, B); g=gcd(g, C);
            A/=g; B/=g; C/=g;
            if (A<0) A=-A, B=-B, C=-C;
            X[cur]=A; Y[cur]=B; Z[cur]=C; I[cur]=i; ID[cur]=cur; cur++;
        }
        sort(ID, ID+cur, cmp);
        int tmp=0, r=0;
        for (int i=0, j; i<cur; i=j) {
            for (j=i+1; j<cur && !cmp(ID[i], ID[j]); j++);
            if (j-i>tmp) {
                tmp=j-i;
                r=i;
            }
        }
        if (tmp) {
            ++flag;
            for (int j=0; j<tmp; j++) vst[id[I[ID[j+r]]]]=flag;
            ans.emplace_back(id[1], id[I[ID[r]]]);
            int m=n; n=0;
            for (int i=2; i<=m; i++) {
                if (vst[id[i]]==flag) continue;
                id[++n]=id[i];
            }
        } else {
            ans.emplace_back(id[1], -1);
            n--;
            for (int i=1; i<=n; i++) id[i]=id[i-1];
            
        }
    }
    
    if (ans.size()>k) puts("NO");
    else {
        puts("YES");
        cout << ans.size() << endl;
        for (auto u : ans) {
            printf("%d %d\n", u.first, u.second);
        }
    }

    return 0;
}