#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 205
int x, y;
int d; int n;
pii co[MN];

bool ok(int cx, int cy){
    cx -= MN; cy -= MN;
    int dsq = cx*cx+cy*cy;
    return dsq <= d*d;
}
int res[MN*4][MN*4][4];
bool calc(int cx, int cy, int st){
    //cout << "doing " << cx-MN << " " << cy-MN << " " << st << "\n";
    if(res[cx][cy][st] != -1) return res[cx][cy][st];
    if(!ok(cx, cy)){
        res[cx][cy][st] = 1;
        return true;
    }
    FOR(i, 1, n){
        int nx = cx+co[i].f, ny=cy+co[i].s;
        if(!calc(nx, ny, 3^st)){
            //cout << cx-MN << " " << cy-MN << " " << st << " win\n";
            res[cx][cy][st] = 1;
            return true;
        }
    }
    if((st&1==0) && !calc(cy, cx, (st|1)^3)){
        res[cx][cy][st] = 1;
        //cout << cx-MN << " " << cy-MN << " " << st << " win\n";
        return true;
    }
    res[cx][cy][st] = 0;
    return false;
}

int main(){
    cin >> x >> y >> n >> d;
    x += MN; y += MN;
    FOR(i, 1, n){
        cin >> co[i].f >> co[i].s;
    }
    memset(res, -1, sizeof res);
    if(calc(x, y, 0)){
        cout << "Anton\n";
    } else{
        cout << "Dasha\n";
    }
    
    return 0;
}