#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 300005
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

double dist(double x1, double y1, double x2, double y2){
    return sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b, c, x1, y1, x2, y2;
    cin >> a >> b >> c;
    cin >> x1 >> y1 >> x2 >> y2;

    double max1 = abs(x2-x1) + abs(y2-y1);

    double inter1x = (-c-y1*b)/a; //(inter1x, y1)
    double dist1x = abs(inter1x-x1);
    double inter1y = (-c-x1*a)/b;
    double dist1y = abs(inter1y-y1);
    double inter2x = (-c-y2*b)/a;
    double dist2x = abs(inter2x-x2);
    double inter2y = (-c-x2*a)/b;
    double dist2y = abs(inter2y-y2);

    double combo1x2x = dist(inter1x, y1, inter2x, y2) + dist1x + dist2x;
    double combo1x2y = dist(inter1x, y1, x2, inter2y) + dist1x + dist2y;
    double combo1y2x = dist(x1, inter1y, inter2x, y2) + dist1y + dist2x;
    double combo1y2y = dist(x1, inter1y, x2, inter2y) + dist1y + dist2y;
    
    cout << setprecision(8) << min(max1, min(min(combo1x2x, combo1x2y), min(combo1y2x, combo1y2y))) << "\n";
    
    return 0;
}