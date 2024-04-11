#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;

const int steps = 16;

ll a[100100];

int main(){
    //freopen("sundaydrive.in", "r", stdin);
    //freopen("sundaydrive.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%I64d", &a[i]);
    }
    ll ans = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = steps; j >= 0; j--){
            if(i + (1 << j) < n){
                a[i + (1 << j)] += a[i];
                ans += a[i];
                break;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}