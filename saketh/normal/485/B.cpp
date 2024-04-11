#include <iostream>
#define INF (1<<30)
using namespace std;

typedef long long ll;

ll N, x, y;
ll xb = -INF, yb = -INF;
ll xs = INF, ys = INF;

int main(){
    for(cin >> N; N; N--){
        cin >> x >> y;
        xb = max(xb, x), xs = min(xs, x);
        yb = max(yb, y), ys = min(ys, y);
    }

    ll sl = max(xb - xs, yb - ys);
    cout << sl * sl << endl;
    return 0;
}