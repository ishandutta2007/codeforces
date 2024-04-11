#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

vector<pii> v;

int n, x[1002], y[1002], r[1002];
int xa, xb, ya, yb;
int main() {
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d %d %d", &x[i], &y[i], &r[i]);
    }
    for(int i=min(xa, xb);i<=max(xa, xb);i++) {
        v.push_back(make_pair(i, ya));
        v.push_back(make_pair(i, yb));
    }
    for(int j=min(ya, yb)+1;j<max(ya, yb);j++) {
        v.push_back(make_pair(xa, j));
        v.push_back(make_pair(xb, j));
    }
    int miss = 0;
    for(int i=0;i<v.size();i++) {
        int cx = v[i].first;
        int cy = v[i].second;
        int ok = 0;
        //printf("%d %d\n", cx, cy);
        for(int j=1;j<=n;j++) {
            if((cx - x[j])*(cx - x[j]) + (cy - y[j])*(cy - y[j]) <= r[j] * r[j]) {
                ok = 1;
                break;
            }
            //printf("%d %d %d %d\n", cx, cy, x[j], y[j]);
        }
        if(ok == 0) miss ++;
    }
    cout << miss << endl;
}