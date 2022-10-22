#include <cstdio>
#include <cstring>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const int N = 4005;
typedef long long LL;
int main() {
     LL X , Y;
     cin >> X >> Y;
     if (__gcd(X , Y) > 1) {
         puts("Impossible");
     } else {
         vector<LL> V;
         vector<char> C;
         while (X > 1 || Y > 1) {
             if (X > Y) {
                 LL t = (X - 1) / Y;
                 V.push_back(t);
                 C.push_back('A');
                 X -= t * Y;
                 
             } else {
                 LL t = (Y - 1) / X;
                 V.push_back(t);
                 C.push_back('B');
                 Y -= t * X;                   
             }
         }
         for (int i = 0 ; i < V.size() ; ++ i)
             printf("%lld%c" , V[i] , C[i]);
     }
     return 0;
}