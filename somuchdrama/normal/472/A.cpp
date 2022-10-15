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



//bool is_prime(int a){
//    for(int i = 0; i < prime.size(); ++i){
//        if(prime[i] == a){
//            return true;
//        }
//    }
//    return false;
//}
bool is_not_prime(int a){
        for(int k = 2; k * k <= a; ++k){
            if(a % k == 0 && a / k > 1)  return true;
        }
        return false;

}

int main(){
    cinn
    for(int i = 4; i < n / 2 + 1; ++i){
        int j = n - i;
        if(is_not_prime(i)){
            if(is_not_prime(j)){
                cout << i << ' ' << j; break;
            }
        }
    }
    return 0;
}