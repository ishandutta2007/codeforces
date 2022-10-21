#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
    point(){x = y = 0;}
    point(int _x, int _y){x = _x, y = _y;}
};

int cross(point a, point b, point r){
    return (a.x - r.x) * (b.y - r.y) - (a.y - r.y) * (b.x - r.x);
}

point sq1[4], sq2[4];

bool insq1(point a){
    if(cross(a, sq1[0], sq1[1]) * cross(a,sq1[3],sq1[2]) > 0) return false;
    return cross(a, sq1[0], sq1[3]) * cross(a,sq1[1],sq1[2]) <= 0;
}

bool insq2(point a){
    if(cross(a, sq2[0], sq2[1]) * cross(a,sq2[3],sq2[2]) > 0) return false;
    return cross(a, sq2[0], sq2[3]) * cross(a,sq2[1],sq2[2]) <= 0;
}

int main(){
    for(int i = 0; i < 4; i++) cin >> sq1[i].x >> sq1[i].y;
    for(int i = 0; i < 4; i++) cin >> sq2[i].x >> sq2[i].y;

    for(int i = 0; i < 4; i++){
        if(insq1(sq2[i])) return !printf("YES");
        if(insq2(sq1[i])) return !printf("YES");
    }
    int midx = 0, midy = 0;
    for(int i = 0; i < 4; i++) midx += sq2[i].x, midy += sq2[i].y;
    int l = 105, r = -105, u = -105, d = 105;
    for(int i = 0; i < 4; i++){
        l = min(l, sq1[i].x);
        r = max(r, sq1[i].x);
        d = min(d, sq1[i].y);
        u = max(u, sq1[i].y);
    }
    if(midx >= 4*l && midx <= 4*r && midy >= 4*d && midy <= 4*u) return !printf("YES");

    return !printf("NO");
}