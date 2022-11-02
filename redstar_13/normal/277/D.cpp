#include <bits/stdc++.h>



using namespace std;

typedef long long INT;

typedef double DO;

typedef pair<int, int> pii;

typedef vector<int> VI;



#define NN 1010



int ss[NN], sl[NN], ts[NN], tl[NN], I[NN], p[NN];

DO pf[NN];

INT exp_s[NN], exp_l[NN];



typedef pair<INT, DO> pid;



pid dp[1600];



#define x first

#define y second



pid operator + (const pid &a, const pid &b) {return pid(a.x+b.x, a.y+b.y);}



template<class T, class U>

inline void smax(T &x, const U &y) {

    if (x<y) x=y;

}



int main() {

#ifndef ONLINE_JUDGE

    freopen("in.in", "r", stdin);

    freopen("out.out", "w", stdout);

#endif



    int n, t;

    cin>>n>>t;

    const int B = 1e6;

    for (int i=1; i<=n; i++) {

        scanf("%d%d%d%d%lf", ss+i, sl+i, ts+i, tl+i, pf+i);

        p[i]=(int)(pf[i]*B+0.5);

        exp_s[i]=(INT)B*ss[i];

        exp_l[i]=(INT)(B-p[i])*sl[i];

        I[i]=i;

    }



    sort(I+1, I+n+1, [&](int u, int v){return (INT)tl[u]*p[u]*(B-p[v])<(INT)tl[v]*p[v]*(B-p[u]);});



    for (int i=0; i<=t; i++) dp[i]=make_pair(-1LL, -1.0);

    dp[0]=make_pair(0, 0);



    for (int i=1; i<=n; i++) {

        int u=I[i];

        for (int j=t; j>=0; j--) {

            if (j-ts[u]>=0) smax(dp[j], dp[j-ts[u]]+make_pair(exp_s[u], -ts[u]));

            int tt=j-ts[u]-tl[u];

            if (tt>=0) {

                smax(dp[j], make_pair(dp[tt].x+exp_s[u]+exp_l[u], (dp[tt].y-ts[u])*pf[u]-j*(1-pf[u])));

            }

        }

    }



    pid ans(0, 0);

    for (int i=0; i<=t; i++) smax(ans, dp[i]);



    printf("%.10lf %.10lf\n", ans.x/1e6, -ans.y);



    return 0;

}