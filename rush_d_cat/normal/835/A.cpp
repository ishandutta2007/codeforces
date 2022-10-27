#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int NICO = 200000+10;
int s, v1, v2, t1, t2;
int a, b;
int main() {
    cin >> s >> v1 >> v2 >> t1 >> t2;
    a = 2 * t1 + s * v1;
    b = 2 * t2 + s * v2;
    if(a > b) printf("Second\n");
    if(a < b) printf("First\n");
    if(a == b) printf("Friendship\n");
}