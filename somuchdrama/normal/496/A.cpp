#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
#include <fstream>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define pb push_back
#define vc vector

//  -

//ifstream IN(".in");
//ofstream OUT(".out")
//

int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

int lcm (int a, int b) {
	return a / gcd (a, b) * b;
}

int main(){
    int n; cin >> n;
    vc<int> A(n);
    for(int i = 0; i < n; ++i){
        cin >> A[i];
    }
    int ans = 10000000;
    for(int i = 1; i < n - 1 ; ++i){
        int t = 0;
        for(int j = 0; j < n - 1; ++j){
            if(j == i - 1){
                continue;
            }
            if(j == i){
                if(A[j + 1] - A[j - 1] > t) t = A[j + 1] - A[j - 1];
            }else{
                if(A[j + 1] - A[j] > t)
                    t = A[j + 1] - A[j];
            }
        }
        if(t < ans){
            ans = t;
        }
    }
    cout << ans;
//    IN.lse();
//    OUT.close();
    return 0;
}