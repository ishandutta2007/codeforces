#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 100000000000001LL
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
#define B1 1000000000
#define B2 999999999
ll xs, ys, xe, ye;
ll n;
string s;

pll dist[MN]; //(x, y)

//bool bad;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> xs >> ys >> xe >> ye >> n >> s;
    //s.resize(n, 'U');

    //if(xe == B1 && ye == B2) bad = true;

    ll dx = xe-xs;
    ll dy = ye-ys;
    
    F0R(i, n){
        dist[i+1] = dist[i];

        if(s[i] == 'U'){
            dist[i+1].s++;
        } else if(s[i] == 'D'){
            dist[i+1].s--;
        } else if(s[i] == 'R'){
            dist[i+1].f++;
        } else{
            dist[i+1].f--;
        }
    }

    ll l = -1, r = INF;
    while(l+1 < r){
        ll mid = (l+r)/2;
        //cout << "checking " << mid << "\n";
        ll dtx = (mid/n)*dist[n].f;
        ll restx = dist[(mid%n)].f;
        //cout << dtx << " " << restx << "\n";

        ll mvx;
        
        if(dx > 0 || (dx == 0 && (dtx+restx) < 0)){
            mvx = dx-(dtx+restx);
            if(mvx < 0) mvx = -mvx;
        } else{
            mvx = -(dx-(dtx+restx));
            if(mvx < 0) mvx = -mvx;
        }

        ll dty = (mid/n)*dist[n].s;
        ll resty = dist[(mid%n)].s;
        //cout << dty << " " << resty << "\n";

        ll mvy;
        
        if(dy > 0 || (dy == 0 && (dty+resty) < 0)){
            mvy = dy-(dty+resty);
            if(mvy < 0) mvy = -mvy;
        } else{
            mvy = -(dy-(dty+resty));
            if(mvy < 0) mvy = -mvy;
        }

        //cout << "dist of x is " << mvx << " and dist of y is " << mvy << "\n";

        ll tot = mvx+mvy;
        if(tot > mid){
            l = mid;
        } else{
            r = mid;
        }
    }

    /*if(bad){
        cout << dist[n].f << " " << dist[n].s << "\n";
    }*/



    if(r == INF){
        cout << "-1\n";
    } else{
        cout << r << "\n";
    }

    return 0;
}