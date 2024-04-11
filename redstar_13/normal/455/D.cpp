#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

const int M = 323;

int a[M*M], n;
int cnt[M][100010];
VI val[M];

void build() {
    for (int i=0; i<M; i++) {
        int st=i*M, ed=min(i*M+M, n);
        if (ed<=st) break;
        val[i].resize(ed-st);
        for (int j=st; j<ed; j++) val[i][j-st]=a[j], cnt[i][a[j]]++;
    }
}

void rebuild() {
    int m=n;
    n=0;
    for (int i=0; i<M; i++) {
        int st=i*M, ed=min(i*M+M, m);
        if (st>=ed) break;
        for (int u : val[i]) a[n++]=u, cnt[i][u]--;
        val[i].clear();
    }
    build();
}

void change(int L, int R) {
    int idL=-1, idR=-1;
    for (int i=0; i<M; i++) {
        if (L<=val[i].size()) {
            idL=i; break;
        }
        L-=val[i].size();
    }
    for (int i=0; i<M; i++) {
        if (R<=val[i].size()) {
            idR=i; break;
        }
        R-=val[i].size();
    }

    VI y(val[idR].size()-1);
    for (int i=0; i<R-1; i++) y[i]=val[idR][i];
    int v=val[idR][R-1];
    for (int i=R; i<val[idR].size(); i++) y[i-1]=val[idR][i];
    cnt[idR][v]--;

    val[idR]=y;

    VI x(val[idL].size()+1);
    for (int i=0; i<L-1; i++) x[i]=val[idL][i];
    x[L-1]=v;
    for (int i=L-1; i<val[idL].size(); i++) x[i+1]=val[idL][i];
    cnt[idL][v]++;

    val[idL]=x;
}

int calc(int L, int R, int k) {
    int idL=-1, idR=-1;
    for (int i=0; i<M; i++) {
        if (L<=val[i].size()) {
            idL=i; break;
        }
        L-=val[i].size();
    }
    for (int i=0; i<M; i++) {
        if (R<=val[i].size()) {
            idR=i; break;
        }
        R-=val[i].size();
    }
    int ans=0;
    for (int i=idL+1; i<idR; i++) ans+=cnt[i][k];
    if (idL==idR) {
        for (int i=L; i<=R; i++) ans+=val[idL][i-1]==k;
    } else {
        for (int i=L-1; i<val[idL].size(); i++) ans+=val[idL][i]==k;
        for (int i=0; i<R; i++) ans+=val[idR][i]==k;
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    
    cin>>n;
    for (int i=0; i<n; i++) scanf("%d", a+i);
    int q, t, L, R, k, ans=0, upd=0;
    build();
    for (cin>>q; q--; ) {
        scanf("%d%d%d", &t, &L, &R);
        L=(L+ans-1)%n+1; R=(R+ans-1)%n+1;
        if (L>R) swap(L, R);
        if (t==1) {
            change(L, R), upd++;
            if (upd==M) rebuild(), upd=0;
        } else {
            scanf("%d", &k);
            k=(k+ans-1)%n+1;
            printf("%d\n", ans=calc(L, R, k));
        }
    }

    return 0;
}