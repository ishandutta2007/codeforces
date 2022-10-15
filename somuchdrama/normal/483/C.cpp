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
#define cinn int n;scanf("%d", &n);
#define cinnm int n,m;cin>>n>>m;
#define cinnk int n,k;cin>>n>>k;
#define vc vector
#define forin for(int i=0;i<n;++i)

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
    cinnk
    vc<char> used(n, 0);
    int prev = 1;
    for(int i = k; i >= 0; --i){
        cout << prev << ' ';
        used[prev] = 1;
        if(i%2==k%2){
            prev+=i;
        }else{
            prev-=i;
        }
    }
    for(int i = k+2; i <= n; ++i)
        cout << i << ' ';
//    IN.lse();
//    OUT.close();
    return 0;
}