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
#define cinnk int n,k;cin>>n>>k;
#define vc vector
#define forin for(int i=0;i<n;++i)

int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

int lcm (int a, int b) {
	return a / gcd (a, b) * b;
}

int main(){
cinnk
    vc<int> A(n);
    int ans = 0;
    forin{
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    for(int i = n - 1; i >= 0; i -= k){
        ans += A[i] - 1;
    }
    cout << ans * 2;
    return 0;
}