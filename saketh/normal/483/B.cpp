#include <iostream>
using namespace std;

long long C1, C2, X, Y;

bool enough(long long M){
    if(M - M/X < C1) return false;
    if(M - M/Y < C2) return false;
    if(M - M/(X*Y) < (C1+C2)) return false;
    return true;
}

int main(){
    cin >> C1 >> C2 >> X >> Y;

    long long ans = 1LL << 60;
    long long lo = C1+C2, hi = 1LL << 60;

    while(lo <= hi){
        long long mi = (lo + hi)/2;
        if(enough(mi)){
            ans = mi;
            hi = mi-1;
        }
        else lo = mi+1;
    }

    cout << lo << endl;
    return 0;
}