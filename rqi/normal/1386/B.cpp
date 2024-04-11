#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef __int128 I;

const ll INF = 1e18;

#define mp make_pair
#define f first
#define s second
#define ins insert
#define lb lower_bound
#define sz(x) (int)(x).size()
void ps(int a){
    cout << a << "\n";
}
int Sf, Pf, Gf;

int g(){
    return 1 + rand()%1000000;
}
// ll abs(ll a){
//     if(a < 0) return -a;
//     return a;
// }

ll gcd(ll a, ll b){
    a = abs(a);
    b = abs(b);
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b%a, a);
}

struct Point{
    pl c;

    Point(int S, int P, int G){
        // cout << x.f << " " << x.s << "\n";
        // cout << y.f << " " << y.s << "\n";
        // cout << X << " " << Y << "\n";

        c = mp(ll(S)*(Sf+Pf+Gf)-ll(Sf)*(S+P+G), ll(P)*(Sf+Pf+Gf)-ll(Pf)*(S+P+G));

        
        assert(c.f <= INF);
        assert(c.s <= INF);
        ll C = gcd(c.f, c.s);
        if(C != 0){
            c.f/=C;
            c.s/=C;
        }
        // cout << c.f << " " << c.s << "\n";
        // cout << "DONE\n";
    }

    Point(pl _c){
        c = _c;
        ll C = gcd(c.f, c.s);
        c.f/=C;
        c.s/=C;
    }

    Point(){

    }

    int half() const {
        if(c.s == 0){
            if(c.f == 0) return 0;
            else if(c.f > 0) return 1;
            return 2;
        }
        if(c.s > 0) return 1;
        return 2;
    }

    bool operator ==(const Point& b) const {
        return (c.f==b.c.f)&(c.s==b.c.s);
    }
    bool operator <(const Point& b) const {
        if(*this == b) return false;
        int A = half();
        int B = b.half();
        if(B == 0) return false;
        if(A == 0) return true;
        if(A != B){
            return A < B;
        }
        return I(c.f)*I(b.c.s)-I(b.c.f)*I(c.s) > I(0);
    }
};

const int mx = 100005;
map<Point, int> m;
Point bot[mx];

int getDoub(Point a){
    if(m.count(a) && m.count(Point(mp(-a.c.f, -a.c.s)))){
        return 1;
    }
    return 0;
}

bool inHalf(){
    // cout << "MULTISET\n";
    // for(auto u: m){
    //     cout << u.c.f << " " << u.c.s << " " << u.half() << "\n";
    // }
    //ps(9);
    if(sz(m) < 3){
        return 1;
    }
    //ps(9);
    if((m.begin())->f.half() == 2) return 1;
    //ps(9);
    if(((prev(m.end())))->f.half() == 1) return 1;
    //ps(9);
    Point a = m.begin()->f;
    Point b = (prev(m.end()))->f;
    if(b < Point(mp(-a.c.f, -a.c.s))) return 1;
    //ps(9);
    a = (prev(m.lb(Point(mp(-1, 0)))))->f;
    b = (m.lb(Point(mp(-1, 0))))->f;
    if(Point(mp(-a.c.f, -a.c.s)) < b) return 1;
    //ps(9);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
    cin >> Sf >> Pf >> Gf;
    // Sf = g();
    // Pf = g();
    // Gf = g();
    int N;
    cin >> N;
    //N = 100000;
    int sing = 0;
    int doub = 0;
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        // cout << "QUERY ";
        // ps(i);
        char typ;
        cin >> typ;
        // if(rand() % 1 == 0) typ = 'A';
        // else typ = 'R';
        if(typ == 'A'){
            int S, P, G;

            cin >> S >> P >> G;
            // S = g();
            // P = g();
            // G = g();

            Point a = Point(S, P, G);
            
            bot[++cnt] = a;
            if(a.half() == 0){
                sing++;
            }
            else{
                doub-=getDoub(a);
                m[a]++;
                doub+=getDoub(a);
            }
            
        }
        else{
            int r;
            //r = 1;
            cin >> r;
            Point a = bot[r];
            //cout << "r " <<  a.c.f << " " << a.c.s << "\n";
            if(bot[r].half() == 0){
                //cout << "R " << i << "\n";
                sing--;
            }
            else{
                doub-=getDoub(a);
                m[a]--;
                if(m[a] == 0) m.erase(a);
                doub+=getDoub(a);
            }
        }
        if(sing > 0){
            ps(1);
            continue;
        }
        if(doub > 0){
            ps(2);
            continue;
        }
        if(inHalf()){
            ps(0);
            continue;
        }
        ps(3);
    }
}