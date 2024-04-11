#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
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

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005

struct Point{
    ll x, y;
    int o;
    int ind;

    bool operator <(const Point &p) const {
        if(x != p.x) return x < p.x;
        return y < p.y;
    }
};

int n;
Point coor[MN];
vector<int> good;

int ccw(int x, int y, int z){
    Point a = coor[x];
    Point b = coor[y];
    Point c = coor[z];
    /*ll dx1 = b.x-a.x;
    ll dy1 = b.y-a.y;
    ll dx2 = c.x-a.x;
    ll dy2 = c.y-a.y;*/
    ll dx1n = a.x-b.x;
    ll dx1d = b.x;
    ll dy1n = a.y-b.y;
    ll dy1d = b.y;
    ll dx2n = a.x-c.x;
    ll dx2d = c.x;
    ll dy2n = a.y-c.y;
    ll dy2d = c.y;
    //got rid of a.x and a.ys cuz i'm p sure they don't affect fin ans

    if(dx1n*dy2n*dy1d*dx2d <= dy1n*dx2n*dx1d*dy2d) return 1; //wtmoo this isn't supposed to overflow
    /*if(dx1*dy2 < dy1*dx2) return -1;

    if((dx1*dx2 < 0) || (dy1*dy2 < 0)) return 1; //1 because on-line is good
    if((dx1*dx1+dy1*dy1) < (dx2*dx2+dy2*dy2)) return 1;

    return 0;*/
    return -1;
}

stack<int> stk;
int scd(){
    int top = stk.top();
    stk.pop();
    int ans = stk.top();
    stk.push(top);
    return ans;
}

bool isHull[MN];
vi hull;

vi ree[MN];

void andrew(){
    stk.push(good[0]);
    FOR(i, 1, good.size()-1){
        while(stk.size() >= 2 && ccw(scd(), stk.top(), good[i]) < 0){
            //cout << "popping " << stk.top() << "\n";
            stk.pop();
        }
        //cout << "pushing " << i << "\n";
        stk.push(good[i]);
    }

    while(!stk.empty()){
        //cout << stk.top() << " ";
        isHull[coor[stk.top()].o] = true;
        for(auto u : ree[stk.top()]){
            isHull[coor[u].o] = true;
        }
        //hull.pb(stk.top());
        stk.pop();
    }
    //cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        int s, r;
        cin >> s >> r;
        coor[i].x = s;
        coor[i].y = r;
        coor[i].o = i+1;
    }
    
    sort(coor, coor+n);

    int mx = 0;
    int prev = n;
    RFOR(i, n-1, 0){
        if(coor[i].y > mx){
            good.pb(i);
            mx = coor[i].y;
            prev = i;
        }
        if(coor[i].x == coor[prev].x && coor[i].y == mx){
            ree[prev].pb(i);
        }
    }
    reverse(good.begin(), good.end());

    andrew();
    
    FOR(i, 1, n){
        if(isHull[i]) cout << i << " ";
    }

    return 0;
}