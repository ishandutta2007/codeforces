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

#define N 1000010
#define s 1000000

int n, a[N]; 
bool c[N]; 
vector<int> S; 
int z[N], L; 

int main() {
    scanf("%d", &n); 
    for (int i = 0; i < n; i ++) scanf("%d", a+i), c[a[i]] = 1; 
    for (int i = 1; i <= s; i ++) 
        if (c[i] && !c[s+1-i]) S.pb(s+1-i); 
    for (int i = 1; i <= s/2; i ++) 
        if (!c[i] && !c[s+1-i]) z[L++] = i; 
    for (int i = 1; i <= s/2; i ++) 
        if (c[i] && c[s+1-i]) {
            int x = z[--L]; 
            S.pb(x); 
            S.pb(s+1-x); 
        }
    sort(S.begin(), S.end()); 
    printf("%d\n", (int) S.size()); 
    for (int i = 0; i < (int) S.size(); i ++) 
        printf ("%d%c", S[i], i == (int) S.size()-1?'\n':' '); 
    return 0; 
}