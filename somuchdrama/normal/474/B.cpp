#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define pb push_back
#define cinn int n;scanf("%d", &n);
#define cinnm int n,m;cin>>n>>m;
#define cinnk int n,k;cin>>n>>k
#define vc vector
#define forin for(int i=0;i<n;++i)

int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

int lcm (int a, int b) {
	return a / gcd (a, b) * b;
}

int main(){
    cinn
    vc<int> A(1000000, 0);
    int t, t1 = 0;
    forin{
        cin >> t;
        for(int j = t1; j < t1 + t; ++j){
            A[j] = i + 1;
        }
        t1 += t;
    }

    int m; cin >> m;
    int t2;
    for(int i = 0; i < m; ++i){
        cin >> t2;
        cout << A[t2 - 1] << "\n";
    }

    return 0;
}