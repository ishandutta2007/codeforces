#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

int main(){
    int n;
    cin >> n;
    map<int, int> A, B, C;
    vector<int> E(n), F(n - 1);
    for(int i = 0; i < n; ++i){
        int t;
        cin >> t;
        E[i] = t;
        A[t]++;
    }
    for(int i = 0; i < n - 1; ++i){
        int t; cin >> t;
        F[i] = t;
        B[t]++;
    }
    for(int i = 0; i < n; ++i){
        if(A[E[i]] > B[E[i]]){
            cout << E[i];
            break;
        }
    }
    for(int i = 0; i < n - 2; ++i){
        int t; cin >> t;
        C[t]++;
    }
    cout << '\n';
    for(int i = 0; i < n - 1; ++i){
        if(B[F[i]] > C[F[i]]){
            cout << F[i];
            break;
        }
    }
    return 0;
}