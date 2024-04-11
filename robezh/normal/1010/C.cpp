#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

int n,k;
int num[N];

int gcd(int x, int y){
    return x == 0 ? y : gcd(y % x, x);
}

int main() {
    scanf("%d%d", &n, &k);
    int g = -1;
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        num[i] %= k;
        if(g == -1 && num[i] != 0) g = num[i];
        else if(num[i] != 0) g = gcd(g, num[i]);
    }
    if(g == -1){
        cout << "1\n0\n";
        return 0;
    }
    g = gcd(g, k);
    printf("%d\n", k / g);
    for(int i = 0; i < k; i += g) printf("%d ", i);


}