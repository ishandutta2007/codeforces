#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ld INF = (ld)1e18, EPS = (ld)1e-10;

ld a,b,c;
ld x[2], y[2];

pair<ld, ld> get_fixed_x(ld x, ld y){
    ld by = - a * x - c;
    if(b == 0){
        if(abs(by) < EPS) return {x, y};
        else return {INF, INF};
    }
    else{
        return {x, by / b};
    }
};

pair<ld, ld> get_fixed_y(ld x, ld y){
    ld ax = - b * y - c;
    if(a == 0){
        if(abs(ax) < EPS) return {x, y};
        else return {INF, INF};
    }
    else{
        return {ax / a, y};
    }
};

ld get_dis(ld x_1, ld y_1, ld x_2, ld y_2){
    return sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
}

ld get_dis(pair<ld, ld> p1, pair<ld, ld> p2){
    if(p1.first == INF || p2.first == INF || p1.second == INF || p2.second == INF) return INF;
    return get_dis(p1.first, p1.second, p2.first, p2.second);
}

int main(){
    cin >> a >> b >> c;
    cin >> x[0] >> y[0] >> x[1] >> y[1];

    pair<ld, ld> s = {x[0], y[0]};
    pair<ld, ld> t = {x[1], y[1]};

    auto s_xfix = get_fixed_x(s.first, s.second);
    auto s_yfix = get_fixed_y(s.first, s.second);

    auto t_xfix = get_fixed_x(t.first, t.second);
    auto t_yfix = get_fixed_y(t.first, t.second);

    ld res = INF;
    res = min(res, get_dis(s, s_xfix) + get_dis(s_xfix, t_xfix) + get_dis(t_xfix, t));
    res = min(res, get_dis(s, s_xfix) + get_dis(s_xfix, t_yfix) + get_dis(t_yfix, t));
    res = min(res, get_dis(s, s_yfix) + get_dis(s_yfix, t_xfix) + get_dis(t_xfix, t));
    res = min(res, get_dis(s, s_yfix) + get_dis(s_yfix, t_yfix) + get_dis(t_yfix, t));

    res = min(res, abs(s.first - t.first) + abs(s.second - t.second));

    cout << fixed << setprecision(10) << res << endl;
}