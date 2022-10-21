#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ld EPS = (ld)1e-8;
const int N = (int)1e5 + 50;

int n;
ld esum = 0;
ll csum = 0;
double x[N];
int res[N];

int is_int(double x) {
    return (int)x == x;
}

int round_down(double x) {
    if(x >= 0 || is_int(x)) return (int)x;
    return -(int)(-x) - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        esum += x[i];
        res[i] = round_down(x[i]);
        csum += res[i];
    }
    for(int i = 0; i < n; i++) {
        if(csum < esum - EPS && !is_int(x[i])) {
            csum++;
            res[i]++;
        }
    }
//    cout << csum << " " << esum << endl;
    for(int i = 0; i < n; i++) cout << res[i] << "\n";


}