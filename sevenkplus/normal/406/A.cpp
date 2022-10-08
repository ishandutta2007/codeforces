#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cassert>
#include <numeric>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII; 
typedef long long ll; 

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define N 1010

int a[N][N];
int n; 

int main() {
    scanf("%d", &n); 
    for (int i = 0; i < n; i ++) 
        for (int j = 0; j < n; j ++) scanf("%d", a[i]+j); 
    int S = 0; 
    for (int i = 0; i < n; i ++) 
        S += a[i][i]; 
    S %= 2; 
    int q; scanf("%d", &q); 
    for (int i = 0; i < q; i ++) {
        int x, y; 
        scanf("%d", &x); 
        if (x == 1) {
            scanf("%d", &y); 
            S ^= 1; 
        } else 
        if (x == 2) {
            scanf("%d", &y); 
            S ^= 1; 
        } else 
        if (x == 3) {
            printf("%d", S); 
        }
    }
    return 0; 
}