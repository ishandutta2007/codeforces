#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 100005;

int n ;
LL X1 , X2 , Y1 , Y2 , A , B , C;

int main() {
    int res = 0;
    cin >> X1 >> Y1;
    cin >> X2 >> Y2 >> n;
    for (int i = 0 ; i < n ; ++ i) {
        cin >> A >> B >> C;
        LL P = A * X1 + B * Y1 + C;
        LL Q = A * X2 + B * Y2 + C;
        res += (P > 0) ^ (Q > 0);
    }
    printf("%d\n" , res);
    return 0;
}