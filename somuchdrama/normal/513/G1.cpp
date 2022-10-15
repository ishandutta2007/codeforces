#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LD;
int n, c;
double ans = 0;
int co = 0;
int azaz = 0;
vector<int> A;
double inver(){
    int res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            if(A[j] < A[i]) ++res;
        }
    }
    return res;
}
void gen(int k){
    if(k == c){
        ++co;
        ans += inver();
        return;
    }
    for(int i = 0; i < n; ++i){
        for (int j = i + 1; j <= n; ++j){
            reverse(&A[i], &A[j]);
            gen(k + 1);
            reverse(&A[i], &A[j]);
        }
    }
}

int main(){
    cin >> n >> c;
    A.resize(n);
    for(int i = 0; i < n; ++i) cin >> A[i];
    gen(0);
    cout << fixed;
    cout.precision(10);
    cout << (ans / co);
//    for(int i = 0; i )
    return 0;
}