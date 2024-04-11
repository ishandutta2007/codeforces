#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define FO(i,a,b) for (int i = (a); i < (b); i++)

namespace simplex {
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define rep(i,n) FO(i,0,n)
#define rtn return
#define mp make_pair
    typedef long double db;
    db inf=1e+18;
    db eps=1e-10;
    inline int sgn(const db& x){rtn (x>+eps)-(x<-eps);}
    const int MAXN=3200; // vars
    const int MAXM=250; // eqs
    int n,m;
    db A[MAXM+1][MAXN+1],X[MAXN];
    int basis[MAXM+1],out[MAXN+1];
    void init(int _n) {
        n = _n; m = 0;
    }
    // maximise sum cf[i]*x[i]
    void setobj(db *cf) {
        FO(i,0,n) A[0][i] = cf[i];
        A[0][n] = 0;
    }
    // sum cf[i]*x[i] <= vl
    void addeq(db *cf, db vl) {
        m++;
        FO(i,0,n) A[m][i] = cf[i];
        A[m][n] = vl;
    }
    void pivot(int a,int b) {
        ft(i,0,m) if (i!=a&&sgn(A[i][b])) ft(j,0,n) if (j!=b) A[i][j]-=A[a][j]*A[i][b]/A[a][b];
        ft(j,0,n) if (j!=b) A[a][j]/=A[a][b];
        ft(i,0,m) if (i!=a) A[i][b]/=-A[a][b];
        A[a][b]=1/A[a][b];
        swap(basis[a],out[b]);
    }
    db simplex() {
        rep(j,n) A[0][j]=-A[0][j];
        ft(i,0,m) basis[i]=-i;
        ft(j,0,n) out[j]=j;
        for(;;) {
            int ii=1,jj=0;
            ft(i,1,m) if (mp(A[i][n],basis[i])<mp(A[ii][n],basis[ii])) ii=i;
            if (A[ii][n]>-eps) break;
            rep(j,n) if (A[ii][j]<A[ii][jj]) jj=j;
            if (A[ii][jj]>-eps) rtn -inf;
            pivot(ii,jj);
        }
        for(;;) {
            int ii=1,jj=0;
            rep(j,n) if (mp(A[0][j],out[j])<mp(A[0][jj],out[jj])) jj=j;
            if (A[0][jj]>-eps) break;
            ft(i,1,m)
                if (A[i][jj]>eps&&(A[ii][jj]<eps||mp(A[i][n]/A[i][jj],basis[i])<mp(A[ii][n]/A[ii][jj],
                                basis[ii])))
                    ii=i;
            if (A[ii][jj]<eps) rtn +inf;
            pivot(ii,jj);
        }
        rep(j,n) X[j]=0;
        ft(i,1,m) if (basis[i]>=0) X[basis[i]]=A[i][n];

       // printf("%lf\n", A[0][n]);

        rtn A[0][n];
    }
};

int n, k;
int ty[123], cc[123];
int sn[123], sc, fr[123];
int var[123][123], vut;

long double cst[123*123];

int ans;

#define EPS 1e-10

int main() {
    scanf("%d %d", &n, &k);

    fo(i,0,n) scanf("%d", ty+i), ty[i]--;
    fo(i,0,n) scanf("%d", cc+i);

    simplex::init(n*(n-1)/2);
    fo(i,0,n) {
        if (!sn[ty[i]]) {
            sn[ty[i]] = 1; sc++;
            if (sc <= k) fr[i] = 1, ans += cc[ty[i]];
        }   
    }
    fo(i,0,n) fo(j,i+1,n) {
        var[i][j] = vut++;
    }
    fo(i,0,n) {
        // set in
        int flin = !fr[i];
        fo(j,0,vut) cst[j] = 0;
        fo(j,0,i) cst[var[j][i]] = -1;
        simplex::addeq(cst, -flin + EPS);
       /* fo(j,0,vut) cst[j] = 0;
        fo(j,0,i) cst[var[j][i]] = 1;
        simplex::addeq(cst, flin + EPS);*/

        // out <= 1
        fo(j,0,vut) cst[j] = 0;
        fo(j,i+1,n) cst[var[i][j]] = 1;
        simplex::addeq(cst, 1 + EPS);
    }
    fo(j,0,vut) cst[j] = 0;
    fo(i,0,n) fo(j,i+1,n) if (ty[i] != ty[j]) cst[var[i][j]] = -cc[ty[j]];
    simplex::setobj(cst);

    printf("%d\n", ans -int(simplex::simplex() - 0.1));

    return 0;
}