#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int x,y,z,t1,t2,t3;
int main() {
    cin>>x>>y>>z>>t1>>t2>>t3;
    int T1 = abs(x-y)*t1;
    int T2 = abs(z-x)*t2 + abs(y-x)*t2 + 3*t3;
    //printf("%d %d\n", T1, T2);
    printf("%s\n", T2 <= T1 ? "YES" : "NO");
}