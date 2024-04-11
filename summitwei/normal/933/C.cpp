#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef long double ld;
#define INF 1000000000LL
#define MOD 1000000007LL
#define EPS 0.00000001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 5
int n;
int x[MN], y[MN], r[MN];
int h[MN];

bool inter(int a, int b){
    ll d1 = (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]);
    return d1 < (r[a]+r[b])*(r[a]+r[b]) && d1 > (r[a]-r[b])*(r[a]-r[b]);
}
/*bool tang(int a, int b){
    ll d1 = (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]);
    return d1 == (r[a]+r[b])*(r[a]+r[b]) && d1 == (r[a]-r[b])*(r[a]-r[b]);
}*/
int res(int a, int b){ //-2 = inside not, -1 = inside tangent, 0 = int, 1 = outside tangent, 2 = outside not
    ll d1 = (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]);
    if(d1 < (r[a]-r[b])*(r[a]-r[b])) return -2;
    if(d1 == (r[a]-r[b])*(r[a]-r[b])) return -1;
    if(d1 > (r[a]+r[b])*(r[a]+r[b])) return 2;
    if(d1 == (r[a]+r[b])*(r[a]+r[b])) return 1;
    return 0;
}

pll add(pll a, pll b){
    return {a.f*b.s+a.s*b.f, a.s*b.s};
}
pll mul(pll a, pll b){
    return {a.f*b.f, a.s*b.s};
}

ld ar(ld a, ld b, ld c){
    ld peri = (a+b+c)/2;
    return sqrt(peri*(peri-a)*(peri-b)*(peri-c));
}

int ni(){
    ll a1, b1, c1, a2, b2, c2;
    a1 = 2*(x[0]-x[1]); b1 = 2*(y[0]-y[1]); c1 = h[1]-h[0];
    a2 = 2*(x[0]-x[2]); b2 = 2*(y[0]-y[2]); c2 = h[2]-h[0];
    //cout << a1 << " " << b1 << " " << c1 << " " << a2 << " " << b2 << " " << c2 << "\n";
    ll den = a1*b2-a2*b1;
    if(den == 0){
        if(x[0] > x[1] || (x[0]==x[1]&&y[0]>y[1])){
            swap(x[0], x[1]); swap(y[0], y[1]); swap(r[0], r[1]);
        }
        if(x[0] > x[2] || (x[0]==x[2]&&y[0]>y[2])){
            swap(x[0], x[2]); swap(y[0], y[2]); swap(r[0], r[2]);
        }
        if(x[1] > x[2] || (x[1]==x[2]&&y[1]>y[2])){
            swap(x[1], x[2]); swap(y[1], y[2]); swap(r[1], r[2]);
        }
        ld d1 = sqrt((x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0]));
        ld d2 = sqrt((x[2]-x[0])*(x[2]-x[0])+(y[2]-y[0])*(y[2]-y[0]));
        ld a1 = ar(r[0], r[1], d1);
        ld a2 = ar(r[0], r[2], d2);
        //cout << fixed << setprecision(3) << d1 << " " << d2 << " " << a1 << " " << a2 << "\n";
        //cout << cnt+1 << "\n";
        if(fabs(a1*d2-a2*d1) <= EPS){
            return 2;
        } else{
            return 0;
        }
    }
    //assert(den != 0);
    pll ix = {c1*b2-b1*c2, den}, iy = {a1*c2-c1*a2, den};
    pll lhs = add(mul(ix, ix), mul(iy, iy));
    pll rhs = add({h[0], 1}, add(mul({2*x[0], 1}, ix), mul({2*y[0], 1}, iy)));
    if(lhs.f*rhs.s != lhs.s*rhs.f){
        return 0;
    } else{
        return 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    if(n == 1){
        cout << "2\n";
        return 0;
    }
    if(n == 2){
        cin >> x[0] >> y[0] >> r[0] >> x[1] >> y[1] >> r[1];
        if(inter(0, 1)){
            cout << "4\n";
        } else{
            cout << "3\n";
        }
        return 0;
    }
    //cin >> x[0] >> y[0] >> r[0] >> x[1] >> y[1] >> r[1] >> x[2] >> y[2] >> r[2];
    F0R(i, 3){
        cin >> x[i] >> y[i] >> r[i];
        h[i] = r[i]*r[i]-x[i]*x[i]-y[i]*y[i];
    }
    int ree[3] = {res(0, 1), res(0, 2), res(1, 2)};
    sort(ree, ree+3);

    //cout << ree[0] << " " << ree[1] << " " << ree[2] << "\n";
    
    if(ree[0] == -2){
        cout << 4+(ree[1]==0)+(ree[2]==0) << "\n";
        return 0;
    }
    if(ree[0] >= 1){
        if(ree[0] == 1 && ree[2] == 1){
            cout << "5\n";
        } else{
            cout << "4\n";
        }
        return 0;
    }
    if(ree[0] == -1){
        if(ree[1] == -1){
            if(ree[2] == -1) cout << "4\n";
            else cout << 6-ree[2] << "\n";
        } else if(ree[1] == 0){
            if(ree[2] == 0){
                cout << 7-ni() << "\n";
            } else{
                cout << 7-ree[2] << "\n";
            }
        } else{
            cout << "4\n";
        }
        return 0;
    }

    if(ree[1] == 0){
        //cout << ni() << "\n";
        if(ree[2] == 2) cout << "6\n";
        else cout << 8-ree[2]-ni() << "\n";
    } else{
        if(ree[2] == 2) cout << "5\n";
        else cout << "6\n";
    }
    
    /*bool ht = tang(0, 1) || tang(0, 2) || tang(1, 2);
    int cnt = 4 + inter(0, 1) + inter(0, 2) + inter(1, 2);
    //cout << inter(0, 1) << " " << inter(0, 2) << " " << inter(1, 2) << "\n";
    if(cnt < 7 || (cnt < 6 && !ht)){
        cout << cnt << "\n";
    } else{
        int a1, b1, c1, a2, b2, c2;
        a1 = 2*(x[0]-x[1]); b1 = 2*(y[0]-y[1]); c1 = h[1]-h[0];
        a2 = 2*(x[0]-x[2]); b2 = 2*(y[0]-y[2]); c2 = h[2]-h[0];
        //cout << a1 << " " << b1 << " " << c1 << " " << a2 << " " << b2 << " " << c2 << "\n";
        int den = a1*b2-a2*b1;
        if(den == 0){
            if(x[0] > x[1] || (x[0]==x[1]&&y[0]>y[1])){
                swap(x[0], x[1]); swap(y[0], y[1]); swap(r[0], r[1]);
            }
            if(x[0] > x[2] || (x[0]==x[2]&&y[0]>y[2])){
                swap(x[0], x[2]); swap(y[0], y[2]); swap(r[0], r[2]);
            }
            if(x[1] > x[2] || (x[1]==x[2]&&y[1]>y[2])){
                swap(x[1], x[2]); swap(y[1], y[2]); swap(r[1], r[2]);
            }
            ld d1 = sqrt((x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0]));
            ld d2 = sqrt((x[2]-x[1])*(x[2]-x[1])+(y[2]-y[1])*(y[2]-y[1]));
            ld a1 = ar(r[0], r[1], d1);
            ld a2 = ar(r[1], r[2], d2);
            //cout << fixed << setprecision(3) << d1 << " " << d2 << " " << a1 << " " << a2 << "\n";
            //cout << cnt+1 << "\n";
            if(fabs(a1*d2-a2*d1) <= EPS){
                cout << cnt-1 << "\n";
            } else{
                cout << cnt+1 << "\n";
            }
            return 0;
        }
        //assert(den != 0);
        pii ix = {c1*b2-b1*c2, den}, iy = {a1*c2-c1*a2, den};
        pii lhs = add(mul(ix, ix), mul(iy, iy));
        pii rhs = add({h[0], 1}, add(mul({2*x[0], 1}, ix), mul({2*y[0], 1}, iy)));
        if(lhs.f*rhs.s != lhs.s*rhs.f){
            cout << cnt+1 << "\n";
        } else{
            cout << cnt << "\n";
        }
    }*/

    return 0;
}