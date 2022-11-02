#include <bits/stdc++.h>



using namespace std;

typedef long long INT;

typedef double DO;

typedef pair<DO, DO> pdd;

typedef vector<int> VI;



#define NN 6060

#define x first

#define y second



pdd p[NN*2];

DO x[NN], ans[NN];



int main() {

#ifndef ONLINE_JUDGE

    freopen("in.in", "r", stdin);

    freopen("out.out", "w", stdout);

#endif



    int n, q, a, b;

    cin>>n>>q>>a>>b;



    int m = 0, j=0;

    DO cur;

    for (int i=1; i<=n; i++) {

        scanf("%lf", x+i);

        if (i==1) {

            p[1]=make_pair(1.0, 2.0*(1.0-x[i]));

            p[2]=make_pair(1e9, 2.0*(1e9-x[i]));

            m=2;

        } else {

            for (int k=m; k>=j+1; k--) p[k+2]=p[k];

            m+=2;

            p[j+1]=p[j+2]=make_pair(cur, 0);

            for (int k=1; k<=j+1; k++) p[k].x+=a;

            for (int k=j+2; k<=m; k++) p[k].x+=b;

            for (int k=1; k<=m; k++) p[k].y+=2.0*(p[k].x-x[i]);

        }

        if (p[1].y>0) cur=p[1].x, j=0;

        else {

            for (j=1; j+1<=m; j++) if (p[j].y<=0 && p[j+1].y>=0) break;

            cur = (p[j+1].x-p[j].x)/(p[j].y-p[j+1].y)*p[j].y+p[j].x;

        }

        ans[i]=cur;

    }



    ans[n]=min(ans[n], (DO)q);

    for (int i=n-1; i>=1; i--) {

        if (ans[i]+b<ans[i+1]) ans[i]=ans[i+1]-b;

        if (ans[i]+a>ans[i+1]) ans[i]=ans[i+1]-a;

    }

    

    DO res=0;

    for (int i=1; i<=n; i++) res+=(ans[i]-x[i])*(ans[i]-x[i]);

    for (int i=1; i<=n; i++) printf("%.8lf ", ans[i]);puts("");

    printf("%.8lf\n", res);



    return 0;

}