#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int SIZE = 60;

int lst[SIZE + 10];
int row[SIZE + 10][100100];
ll a[100100];
int ans[100100];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf(LLD, &a[i]);
    }
    ll s = 0;
    for(int i = 0; i < n; i++){
        s ^= a[i];
    }
    int sz = 0;
    for(int i = 0; i < 2; i++){
        for(int j = SIZE; j >= 0; j--){
            if(((s >> j) & 1) == i){
                for(int z = 0; z < n; z++){
                    row[sz][z] = ((a[z] >> j) & 1);
                }
                row[sz][n] = 1;
                for(int z = 0; z < sz; z++){
                    if(row[sz][lst[z]] > 0){
                        for(int h = 0; h <= n; h++){
                            row[sz][h] ^= row[z][h];
                        }
                    }
                }
                int pos = 0;
                while(pos < n && row[sz][pos] == 0){
                    pos++;
                }
                if(pos < n){
                    lst[sz++] = pos;
                }
            }
        }
    }
    for(int i = sz - 1; i >= 0; i--){
        ans[lst[i]] = row[i][n];
        for(int j = i + 1; j < sz; j++){
            ans[lst[i]] ^= (ans[lst[j]] & row[i][lst[j]]);
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d ", ans[i] + 1);
    }
    printf("\n");
    return 0;
}