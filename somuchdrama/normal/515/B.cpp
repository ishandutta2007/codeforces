#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;


int main(){
    int n, m;
    cin >> n >> m;
    bool A[n], B[m];
    for(int i = 0; i < n; ++i) A[i] = 0;
    for(int i = 0; i < m; ++i) B[i] = 0;
    int a, b;
    cin >> a;
    for(int i = 0; i < a; ++i){
        int t; cin >> t;
        A[t] = 1;
    }
    cin >> b;
    for(int i = 0; i < b; ++i){
        int t; cin >> t;
        B[t] = 1;
    }
    for(int i = 0; i < 100000; ++i){
        if(A[i % n]){
            B[i % m] = 1;
        }else if(B[i % m]){
            A[i % n] = 1;
        }
    }
    bool ok = true;
    for(int i = 0; i < n; ++i){
        if(!(A[i])){
            ok = false;
        }
    }
    for(int i = 0; i < m; ++i){
        if(!B[i]){
            ok = false;
        }
    }
    cout << (ok ? "Yes" : "No");
    return 0;
}