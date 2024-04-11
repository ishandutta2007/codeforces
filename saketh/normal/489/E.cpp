#include <iostream>
#include <cmath>
using namespace std;

int N, L, x[1005], b[1005], p[1005];
double sp[1005];

double paths(double ratio){
    sp[0] = 0;
    for(int i=1; i<=N; i++){
        sp[i] = 1e50;
        for(int j=0; j<i; j++){
            double val = sp[j] + sqrt(fabs(x[i] - x[j] - L));
            val -= ratio * b[i];
            if(val < sp[i]){
                sp[i] = val;
                p[i] = j;
            }
        }
    }
    return sp[N];
}

void trace(int loc){
    if(loc == 0) return;
    trace(p[loc]);
    cout << loc << " ";
}

int main(){
    cin >> N >> L;
    x[0] = 0;
    b[0] = 0;
    for(int i=1; i<=N; i++)
        cin >> x[i] >> b[i];

    double lo = 0, hi = 1e6;
    while((hi - lo) > 1e-7){
        double mi = (lo + hi)/2;
        if(paths(mi) > 0) lo = mi;        
        else hi = mi;
    }

    paths(lo);
    trace(N);
    cout << endl;
    return 0;
}