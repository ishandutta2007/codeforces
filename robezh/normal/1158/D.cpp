#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const double EPS = 1e-9;
const double PI = 3.14159265;

struct point{
    int x,y;
    int i;
    point(int _x, int _y): x(_x), y(_y) {}
    point(int _x, int _y, int _i): x(_x), y(_y), i(_i) {}

    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
    point operator + (point other) const{
        return point(x + other.x, y + other.y);
    }
};

double dist(point a,point b){
    return hypot(a.x - b.x, a.y - b.y);
}

struct vec {
    int x,y;
    vec(int _x, int _y): x(_x), y(_y) {}
};

vec toVec(point &a, point &b){
    return vec(b.x - a.x, b.y - a.y);
}

ll cross(vec a, vec b){
    return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

bool ccw(point &p, point &q, point &r){
    return cross(toVec(p,q),toVec(q,r)) > 0;
}

point pivot = point(0,0);
bool angleCmp(point &a, point &b){
    return cross(toVec(pivot, a), toVec(pivot, b)) > 0;
}

void find(vector<point> P, vector<point> &S){
    int i,j,n = (int)P.size();
    if(n <= 2){
        S = P;
        return ;
    }
    int P0 = 0;
    for(i = 1; i < n; i++)
        if(P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;

    point temp = P[0]; P[0] = P[P0]; P[P0] = temp;

    pivot = P[0];

    sort(P.begin()+1, P.end(), angleCmp);

    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
    i = 2;
    while(i < n){
        j = (int) S.size() - 1;
        if(ccw(S[j-1],S[j],P[i])) S.push_back(P[i++]);
        else S.pop_back();
    }
    S.pop_back();
    //printf("smallest %lf %lf\n", P[0].x, P[0].y);
}

int n;
vector<point> rem;
vector<int> res;
string str;
int la = -1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        rem.push_back({x, y, i});
    }
    cin >> str;
//    for(auto p : rem) cout << p.x << " " << p.y << endl;
    for(int turn = 0; turn < n - 1; turn++) {
        vector<point> hull;
        find(rem, hull);
        int sz = hull.size();
        if(la == -1) {
            la = hull[0].i;
            res.push_back(la);
        }
        int id = -1;
        for(int i = 0; i < hull.size(); i++) if(hull[i].i == la) {
                id = i; break;
            }
        int nxt;
        if(turn == n - 2 || str[turn] == 'L') nxt = hull[(id+1)%sz].i;
        else nxt = hull[(id+sz-1)%sz].i;

        res.push_back(nxt);

        for(int i = 0; i < rem.size(); i++) {
            if(rem[i].i == la) {
                rem.erase(rem.begin() + i);
                break;
            }
        }
        vector<point> new_rem;
        for(auto &p : rem) if(la != p.i) new_rem.push_back(p);

        la = nxt;
    }
    for(int i = 0; i < n; i++) cout << res[i] + 1 << " ";
}