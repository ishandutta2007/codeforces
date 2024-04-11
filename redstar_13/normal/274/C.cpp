#include <bits/stdc++.h>



using namespace std;

typedef long long INT;

typedef double DO;

typedef pair<int, int> pii;

typedef vector<int> VI;



#define x first

#define y second



pii p[111];

map<pii, int> mp;



pii operator + (const pii &a, const pii &b) {return make_pair(a.x+b.x, a.y+b.y);}

pii operator - (const pii &a, const pii &b) {return make_pair(a.x-b.x, a.y-b.y);}

int operator * (const pii &a, const pii &b) {return a.x*b.x+a.y*b.y;}

int operator ^ (const pii &a, const pii &b) {return a.x*b.y-a.y*b.x;}



pii conj(const pii &a) {return pii(-a.y, a.x);}



int main() {

#ifndef ONLINE_JUDGE

    freopen("in.in", "r", stdin);

    freopen("out.out", "w", stdout);

#endif



    int n;

    cin>>n;

    for (int i=1; i<=n; i++) {

        scanf("%d%d", &p[i].x, &p[i].y);

        mp[p[i]]=1;

    }



    DO ans=0;

    auto can=[&](DO x, DO y, DO r) {

        for (int i=1; i<=n; i++) if ((x-p[i].x)*(x-p[i].x)+(y-p[i].y)*(y-p[i].y)<r*r-1e-8) return 0;

        return 1;

    };

    for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) {

        for (int k=j+1; k<=n; k++) {

            int a=(p[j]-p[k])*(p[j]-p[k]);

            int b=(p[i]-p[k])*(p[i]-p[k]);

            int c=(p[i]-p[j])*(p[i]-p[j]);

            if (a>b+c || b>a+c || c>a+b) continue;

            pii A=p[i], B=p[j], C=p[k];

            if (a<b) swap(A, B), swap(a, b);

            if (a<c) swap(A, C), swap(a, c);

            if (a==b+c) {

                pii D = B + C - A;

                if (mp.count(D)) {

                    DO val=sqrt(a)/2;

                    if (can(0.5*(B.x+C.x), 0.5*(B.y+C.y), val) && ans<val) ans=val;

                }

            } else {

                pii E=conj(C-A), F=conj(B-A), G=B-C;

                DO t = 0.5*(F^G)/(F^E), val;

                DO x = 0.5*(A.x+C.x)+t*E.x;

                DO y = 0.5*(A.y+C.y)+t*E.y;

                if (can(x, y, val=sqrt((x-A.x)*(x-A.x)+(y-A.y)*(y-A.y)))) {

                    if (ans<val) ans = val;

                }

            }

        }

    }



    if (ans<1e-8) puts("-1");

    else cout << fixed << setprecision(10) << ans << endl;



    return 0;

}