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
    int x; cin >> x;
    vc<pair<int, int> > A(n);
    for(int i = 0; i < n; ++i) {
    int t1, t2;
    cin >> t1 >> t2;
    ++t2;
       A[i] = make_pair(t1, t2);
    }
    int ans = 0;
    int r = 1;
    for(int i = 0; i < n; ++i){
//        cout << ans << "\n";
        ans += (A[i].first - r) % x;
        ans += A[i].second - A[i].first;
        r = A[i].second;
    }
    cout << ans;
//    IN.lse();
//    OUT.close();
    return 0;
}