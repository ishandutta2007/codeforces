#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

#define NN 101010

int y[NN];
INT ans=1LL<<60;

inline void smin(INT &x, const INT &y) {if (x>y) x=y;}

pii p1[NN], p2[NN], p[NN];

int sgn(const pii &a, const pii &b, const pii &c) {
    return (INT)(a.first-b.first)*(c.second-b.second)>=(INT)(a.second-b.second)*(c.first-b.first);
}

void make_convex(pii *p0, int &n) {
    for (int i=0; i<n; i++) p[i]=p0[i];
    sort(p, p+n);
    int m=0;
    for (int i=0; i<n; i++) {
        while (m>1 && sgn(p0[m-2], p0[m-1], p[i])) m--;
        p0[m++]=p[i];
    }
    for (int i=n-2, t=m; i>=0; i--) {
        while (m>t && sgn(p0[m-2], p0[m-1], p[i])) m--;
        p0[m++]=p[i];
    }
    if (m<3) n=m;
    else n=m-1;
}

pii operator + (const pii &a, const pii &b) {return make_pair(a.first+b.first, a.second+b.second);}
pii operator - (const pii &a, const pii &b) {return make_pair(a.first-b.first, a.second-b.second);}

INT operator ^ (const pii &a, const pii &b) {return (INT)a.first*b.second-(INT)a.second*b.first;}
int sgn(INT x) {return (x>0)-(x<0);}

int minkowski(pii *p1, pii *p2, int &n, int m) {
    int size = 0;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; ++i) if (p1[i] < p1[s1]) s1 = i;
    for (int i = 0; i < m; ++i) if (p2[i] < p2[s2]) s2 = i;
    p1[n] = p1[0];
    p2[m] = p2[0];
    int i = s1, j = s2;
    do {
        p[size++] = p1[i] + p2[j];
        int cp = sgn((p1[i+1] - p1[i]) ^ (p2[j+1] - p2[j]));
        if (cp > 0) ++i;
        else if (cp < 0) ++j;
        else ++i, ++j;
        i %= n; j %= m;
    } while(i != s1 || j != s2);
    n=size;
    for (int i=0; i<n; i++) p1[i]=p[i];
}

void solve(int st, int ed) {
    if (ed-st<10) {
        for (int i=st; i<ed; i++) {
            int s=0;
            for (int j=i; j<ed; j++) {
                s+=y[j];
                smin(ans, (INT)s*s+(j-i+1)*(j-i+1));
            }
        }
		return ;
    }
    int mid=st+ed>>1;
    solve(st, mid); solve(mid, ed);
    int n=mid-st, m=ed-mid;
    p1[0]=make_pair(1, y[mid-1]);
    for (int i=1; i<n; i++) p1[i]=make_pair(i+1, p1[i-1].second+y[mid-i-1]);
    p2[0]=make_pair(1, y[mid]);
    for (int i=1; i<m; i++) p2[i]=make_pair(i+1, p2[i-1].second+y[mid+i]);
    make_convex(p1, n); make_convex(p2, m);
    minkowski(p1, p2, n, m);
    for (int i=0; i<n; i++) 
        smin(ans, (INT)p1[i].first*p1[i].first+(INT)p1[i].second*p1[i].second);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    int n;
    cin>>n;
    for (int i=1; i<=n; i++) scanf("%d", y+i);
    solve(2, n+1);

    cout << ans << endl;

    return 0;
}