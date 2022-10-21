#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N = (int)1e5 + 500;
const ld INF = (ld)1e18;

struct point{
    ld x, y;
    point(){x = y = 0;}
    point(ld _x, ld _y){
        x = _x, y = _y;
    }
};

ld get_dis(point p1, point p2){
    return (p1.x - p2.x) * (p1.x - p2.x) +  (p1.y - p2.y) * (p1.y - p2.y);
}

int n;
ll num[N];
point pt[N];

ld solve(int L, int R){
    if(L == R) return INF;
    //if(L + 1 == R) return get_dis(pt[L], pt[R]);

    int mid = (L + R) / 2;
    ld midx = (pt[mid].x + pt[mid+1].x) / 2;
    ld LHS = solve(L, mid), RHS = solve(mid+1, R);
    ld res = min(LHS, RHS);
    ld dis = sqrt(res);
    //cout << "midx = " << midx << endl;

//    vector<point> left, right;
//    for(int i = L; i <= R; i++){
//        if(pt[i].x >= midx - dis && pt[i].x <= midx) left.push_back(pt[i]);
//        else if(pt[i].x > midx && pt[i].x <= midx + dis) right.push_back(pt[i]);
//    }
//    int ri_down = 0, ri_up = 0;
//    for(int i = 0; i < left.size(); i++){
//        while(ri_up < right.size() && right[ri_up].y <= left[i].y + dis){ri_up ++;}
//        while(ri_down < right.size() && right[ri_down].y < left[i].y - dis){ri_down ++;}
//        for(int j = ri_down; j < ri_up; j++){
//            res = min(res, get_dis(left[i], right[j]));
//        }
//    }

    vector<point> sorted;
    int r = mid+1;
    for(int l = L; l <= mid; l++){
        while(r <= R && pt[r].y < pt[l].y) sorted.push_back(pt[r++]);
        sorted.push_back(pt[l]);
    }
    while(r <= R) sorted.push_back(pt[r++]);
    assert(sorted.size() == R - L + 1);
    for(int i = L; i <= R; i++) pt[i] = sorted[i - L];

    vector<point> tot;
    for(int i = L; i <= R; i++){
        if(fabs(pt[i].x - midx) <= dis) tot.push_back(pt[i]);
    }
    int up = 0;
    for(int i = 0; i < tot.size(); i++){
        while(up < tot.size() && tot[i].y + dis > tot[up].y) up++;
        for(int j = i+1; j < up; j++) res = min(res, get_dis(tot[i], tot[j]));
    }

    return res;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%I64d", &num[i]);
    for(int i = 1; i < n; i++) num[i] += num[i-1];
    for(int i = 0; i < n; i++) pt[i] = point(i, num[i]);

    //for(int i = 0; i < n; i++) cout << pt[i].x << " " << pt[i].y << endl;
    ll res = (ll)solve(0, n-1);
    for(int i = 0; i < n-1; i++){
        assert(pt[i].y <= pt[i+1].y);
    }
    cout << res << endl;
}