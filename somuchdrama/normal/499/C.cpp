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
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n; cin >> n;
    long long A[n][3];
    for(int i = 0; i < n; ++i){
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        if((A[i][0] * x1 + A[i][1] * y1 + A[i][2] >= 0 and A[i][0] * x2 + A[i][1] * y2 + A[i][2] >= 0) or (A[i][0] * x1 + A[i][1] * y1 + A[i][2] <= 0 and A[i][0] * x2 + A[i][1] * y2 + A[i][2] <= 0)){
            continue;
        }else{
            ++ans;
        }
    }
    cout << ans;
//    IN.lse();
//    OUT.close();
    return 0;
}