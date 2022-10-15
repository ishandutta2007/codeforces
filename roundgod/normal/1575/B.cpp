#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

typedef double db;

const db eps = 1e-6;
const db pi = acos(-1);

int dcmp(db x) {
    return x < -eps ? -1 : x > eps;
}

db myacos(db x) {
    if (x < -1) x = -1;
    if (x > 1) x = 1;
    return acos(x);
}

db myasin(db x) {
    if (x < -1) x = -1;
    if (x > 1) x = 1;
    return asin(x);
}

db mysqrt(db x) {
    return x < 0 ? 0 : sqrt(x);
}

typedef struct P {
    db x, y;

    P(db x = 0, db y = 0) : x(x), y(y) {}
    P operator+(P r) { return P(x + r.x, y + r.y); }
    P operator-(P r) { return P(x - r.x, y - r.y); }
    P operator*(db r) { return P(x * r, y * r); }
    P operator/(db r) { return P(x / r, y / r); }
    bool operator==(const P &r) const { return dcmp(x - r.x) == 0 && dcmp(y - r.y) == 0; }
    bool upper() { return y > 0 || (y == 0 && x > 0); }
    void read() { scanf("%lf %lf", &x, &y); }
    void print() { printf("%.2f %.2f\n", x, y); }
}V;

db Cross(V A, V B) { return A.x*B.y - A.y*B.x; }

bool operator <(P a, P b) {
    if(a.upper() != b.upper()) return a.upper() < b.upper();
    return Cross(a, b) > 0;
}

struct Circle {
    P c;
    db r;
    Circle(){}
    Circle(P c, db r) : c(c), r(r) {}
    //
    P point(db a) {
        return P(c.x + cos(a)*r, c.y + sin(a)*r);
    }
};

V Rotate(V A, db rad) {
    return V(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

db Dot(V A, V B) { return A.x*B.x + A.y*B.y; }

db Length(V A) { return mysqrt(Dot(A, A)); }

vector<P> GetTangents(P p, Circle C) {
    V u = C.c - p;
    db dist = Length(u);
    vector<P> v;
    if(dist < C.r) return v;
    else if(dcmp(dist - C.r) == 0) {
        v.emplace_back(p);
        return v;
    } else {
        db ang = myasin(C.r / dist);
        V v1 = Rotate(Rotate(u, ang), pi / 2);
        v1 = v1 / Length(v1) * C.r;
        assert(dcmp(Dot(v1 - p, v1)) == 0);
        V v2 = Rotate(Rotate(u, -ang), pi / 2);
        v2 = v2 * (-1);
        v2 = v2 / Length(v2) * C.r;
        assert(dcmp(Dot(v2 - p, v2)) == 0);
        v.emplace_back(v1);
        v.emplace_back(v2);
        return v;
    }
}

const int maxn = 4e5 + 233;
db R;
int n, k;
P point[maxn];
int cnt[maxn];

bool check(db mid){
    vector<P> lst;
    for (int i = 1; i <= n; i += 1) {
        auto cur = GetTangents(point[i], Circle(P(0, 0), mid));
        for (auto it : cur) {
            lst.emplace_back(it);
        }
    }  
    sort(lst.begin(), lst.end());
    lst.erase(unique(lst.begin(), lst.end()), lst.end());

    /*
    for (auto it: lst) {
        it.print(); 
    }
    puts("\n\n\n");
    */
    memset(cnt, 0, sizeof(cnt));
    int len = lst.size();
    for (int i = 1; i <= n; i += 1) {
        auto cur = GetTangents(point[i], Circle(P(0, 0), mid));
        if(cur.size() == 0) continue;
        if(cur.size() == 1) {
            int p = lower_bound(lst.begin(), lst.end(), cur[0]) - lst.begin() + 1;
            cnt[p] += 1;
            cnt[p + 1] -= 1;
        }
        if(cur.size() == 2) {
            int l = lower_bound(lst.begin(), lst.end(), cur[0]) - lst.begin() + 1;
            int r = lower_bound(lst.begin(), lst.end(), cur[1]) - lst.begin() + 1;
            
            /*
            point[i].print();
            cur[0].print();
            cur[1].print();

            puts("");
            */
            
            if(l <= r) {
                cnt[l] += 1;
                cnt[r + 1] -= 1;
            }
            else{
                cnt[l] += 1;
                cnt[len + 1] -= 1;
                cnt[1] += 1;
                cnt[r + 1] -= 1;
            }
        }
    } 
    for (int i = 1; i <= len; i += 1){
        cnt[i] += cnt[i - 1];
        if(cnt[i] >= k) {
            return true;
        }
    }
    return false;
}

int main(){
    scanf("%d %d", &n, &k);
    db mx = 1, mn = 1e6;
    int cur = 0;
    for (int i = 1; i <= n; i += 1) {
        point[i].read();
        if(point[i] == P(0, 0)) {
            k -= 1;
        }
        else{
            point[++cur] = point[i];
            mx = max(mx, abs(point[i].x) + 1);
            mn = min(mn, abs(point[i].x) + 1);
            mx = max(mx, abs(point[i].y) + 1);
            mn = min(mn, abs(point[i].y) + 1);
        }
    }
    n = cur;
    if(k <= 0) {
        puts("0.000000000000");
        return 0;
    }
    
    R = mx * mn;

    for (int i = 1; i <= n; i += 1) {
        point[i] = point[i] * (R / Dot(point[i], point[i]));
        //point[i].print();
    }

    
    db lo = 1e-4, hi = R;

    for (int i = 1; i <= 45; i += 1){
        db mid = (lo + hi) / 2;
        if(check(mid)) lo = mid;
        else hi = mid;
    }
    
    printf("%.10f\n", 0.5 * R / lo);
    
    return 0;
}