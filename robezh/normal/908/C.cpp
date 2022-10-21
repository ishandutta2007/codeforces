#include <bits/stdc++.h>
using namespace std;

int n,r;

int upp[1005];
double x[1005];
double y[1005];

double getLowestDy(int now){
    double res = r;
    for(int i = 0; i < now; i++){
        double dx = abs(x[i] - x[now]);
        double dt = 2 * r;
        if(dx > dt) continue;
        double dy = sqrt(dt * dt - dx * dx);
        res = max(dy+y[i], res);
    }
    return res;
}

int main() {
    for(int i = 1; i <= 1000; i++) upp[i] = -1;
    cin >> n >> r;
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++){
        y[i] = getLowestDy(i);
    }
    for(int i = 0; i < n; i++) cout << fixed << setprecision(10) << y[i] << " ";
}