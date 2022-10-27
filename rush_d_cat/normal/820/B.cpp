#include <iostream>
#include <cmath>
using namespace std;
int n, a;
int main() {
    cin >> n >> a;
    double c = 180.0 / n;
    int k = 0;
    double best = 10000000;
    for(int i=3;i<=n;i++) {
        if(abs((i-2) * c - a) < best) {
            best = abs((i-2) * c - a);
            k = i;
        }
    }
    printf("%d %d %d\n", 2, 1, k);
}