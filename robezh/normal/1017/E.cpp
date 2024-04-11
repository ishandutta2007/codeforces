#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;


const double EPS = 1e-4;
const double PI = 3.14159265;
const int N = (int)1e5 + 500;

struct point{
    double x,y;
    point(double _x, double _y): x(_x), y(_y) {}

    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
    bool operator < (point other) const {
        return (fabs(x - other.x) < EPS) ? y < other.y : x < other.x;
    }
    bool operator > (point other) const {
        return (fabs(x - other.x) < EPS) ? y > other.y : x > other.x;
    }
    point operator + (point other) const{
        return point(x + other.x, y + other.y);
    }
};

vector<point> pt[2];

double dist(point a,point b){
    return hypot(a.x - b.x, a.y - b.y);
}

point rotate(point p, double theta){
    double rad = theta * PI / 180.0;
    return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

struct vec {
    double x,y;
    vec(double _x, double _y): x(_x), y(_y) {}
};


vec toVec(point a, point b){
    return vec(b.x - a.x, b.y - a.y);
}

double cross(vec a, vec b){
    return a.x * b.y - a.y * b.x;
}

//double angle(point p, point q, point r){
//    double a = dist(p, q), b = dist(q, r), c = dist(r, p);
//    return -acos((a * a + b * b - c * c) / (2 * a * b));
//}

bool ccw(point p, point q, point r){
    return cross(toVec(p,q),toVec(q,r)) > EPS;
}

bool colinear(point p, point q, point r){
    return fabs(cross(toVec(p,q),toVec(q,r))) <  EPS;
}

point pivot = point(0,0);
bool angleCmp(point a, point b){
    if(colinear(pivot,a,b)) return dist(pivot,a) < dist(pivot, b);
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    double at1 = atan2(d1y,d1x), at2 = atan2(d2y, d2x);
    return at1 - at2 < 0;
}

vector<point> CH(vector<point> P){
    int i,j,n = (int)P.size();
    if(n <= 2){
        if(!(P[0] == P[n-1])) P.push_back(P[0]);
        return P;
    }
    int P0 = 0;
    for(int i = 1; i < n; i++)
        if(P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;

    point temp = P[0]; P[0] = P[P0]; P[P0] = temp;

    pivot = P[0];

    sort(P.begin()+1, P.end(), angleCmp);

    vector<point> S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
    i = 2;
    while(i < n){
        j = (int) S.size() - 1;
        if(ccw(S[j-1],S[j],P[i])) S.push_back(P[i++]);
        else S.pop_back();
    }
    //printf("smallest %lf %lf\n", P[0].x, P[0].y);
    return S;
}

bool all_co_linear(const vector<point> &pt){
    for(int i = 2; i < pt.size(); i++){
        if(!colinear(pt[0], pt[1], pt[i])) return false;
    }
    return true;
}

vector<double> s, t;
int f[2*N];

void getnext(){
    int m = t.size();
    f[0] = 0; f[1] = 0;
    for(int i = 1; i < m; i++){
        int j = f[i];
        while(j && fabs(t[i] - t[j]) > EPS) j = f[j];
        f[i+1] = (fabs(t[i] - t[j]) < EPS) ? j + 1 : 0;
    }
}

bool find(){
    int n = s.size(), m = t.size();
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j && fabs(t[j] - s[i]) > EPS) j = f[j];
        if(fabs(t[j] - s[i]) < EPS) j++;
        if(j == m) return true;
    }
    return false;
}

int main(){

    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++){
        double a, b;
        scanf("%lf%lf", &a, &b);
        pt[0].push_back(point(a,b));
    }
    for(int i = 0; i < m; i++){
        double a, b;
        scanf("%lf%lf", &a, &b);
        pt[1].push_back(point(a,b));
    }

    bool co1 = all_co_linear(pt[0]), co2 = all_co_linear(pt[1]);
    if(co1 ^ co2) return !printf("NO");
    if(co1){
        double dis[2];
        for(int t = 0; t < 2; t++){
            int mni = 0, mxi = 0;
            for(int i = 0; i < pt[t].size(); i++){
                if(pt[t][i] < pt[t][mni]) mni = i;
                if(pt[t][i] > pt[t][mxi]) mxi = i;
            }
            dis[t] = dist(pt[t][mxi], pt[t][mni]);
        }
        return !printf(fabs(dis[0] - dis[1]) < EPS ? "YES" : "NO");
    }

    auto CH0 = CH(pt[0]), CH1 = CH(pt[1]);

    //cout << CH0.size() << " " << CH1.size() << endl;
    CH0.pop_back();
    CH1.pop_back();
    for(int w = 0; w < 2; w++){
        for(int i = 0; i < CH0.size(); i++){
            s.push_back(dist(CH0[i], CH0[(i+1)%CH0.size()]));
            //s.push_back(angle(CH0[i], CH0[(i+1)%CH0.size()], CH0[(i+2)%CH0.size()]));
            s.push_back(-dist(CH0[i], CH0[(i+2)%CH0.size()]));
        }
    }
    for(int i = 0; i < CH1.size(); i++){
        t.push_back(dist(CH1[i], CH1[(i+1)%CH1.size()]));
        //t.push_back(angle(CH1[i], CH1[(i+1)%CH1.size()], CH1[(i+2)%CH1.size()]));
        t.push_back(-dist(CH1[i], CH1[(i+2)%CH1.size()]));
    }
//    for(double x : s) cout << x << " ";
//    cout << endl;
//    for(double x : t) cout << x << " ";
//    cout << endl;

    getnext();
    if(find()) printf("YES");
    else printf("NO");

}