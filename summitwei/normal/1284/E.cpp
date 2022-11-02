#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 2505
struct Point{
    ll x, y;
 
    bool operator <(const Point &p) const {
        if(x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator ==(const Point &p) const {
        return x==p.x && y==p.y;
    }
};
 
int n;
Point orig[MN];
Point a[MN];
Point cur;
 
int ccw(Point a, Point b, Point c){
    ll dx1 = b.x-a.x;
    ll dy1 = b.y-a.y;
    ll dx2 = c.x-a.x;
    ll dy2 = c.y-a.y;
 
    if(dx1*dy2 > dy1*dx2) return 1;
    if(dx1*dy2 < dy1*dx2) return -1;
 
    if((dx1*dx2 < 0) || (dy1*dy2 < 0)) return -1;
    if((dx1*dx1+dy1*dy1) < (dx2*dx2+dy2*dy2)) return 1;
 
    return 0;
}
 
bool ndf(Point a){
    return a.y<cur.y || (a.y==cur.y && a.x<cur.x);
}
Point ref(Point a){
    a.y = cur.y*2-a.y;
    a.x = cur.x*2-a.x;
    return a;
}
 
bool comp(Point a, Point b){
    if(a == cur) return false;
    if(b == cur) return true;
    if(ndf(a)) a = ref(a);
    if(ndf(b)) b = ref(b);
    return ccw(b, cur, a) == 1;
}
 
ll c3(ll x){
    return x*(x-1)*(x-2)/6;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    F0R(i, n){
        cin >> a[i].x >> a[i].y;
        orig[i] = a[i];
    }
 
    ll bd = 0;
 
    F0R(i, n){
        cur = orig[i];
        sort(a, a+n, comp);
        ll bot = 0;
        ll top = 0;
        F0R(j, n-1){
            if(ndf(a[j])){
                ++top;
            } else{
                ++bot;
            }
        }
        F0R(j, n-1){
            if(ndf(a[j])){
                --top;
            } else{
                --bot;
            }
            bd += c3(bot);
            bd += c3(top);
            if(ndf(a[j])){
                ++bot;
            } else{
                ++top;
            }
        }
    }
    
    ll tot = n*(n-1)*c3(n-2)/4;
    //cout << bd << "\n";
    cout << tot-bd/2 << "\n";
 
    return 0;
}