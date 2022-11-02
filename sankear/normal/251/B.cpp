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

int q[111], s[111], go1[111], go2[111], p[111], np[111];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &q[i]);
        q[i]--;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &s[i]);
        s[i]--;
    }
    bool fl = true;
    for(int i = 0; i < n; i++){
        if(s[i] != i){
            fl = false;
            break;
        }
    }
    if(fl){
        printf("NO\n");
        return 0;
    }
    for(int i = 0; i < n; i++){
        go1[i] = q[i];
        go2[q[i]] = i;
    }
    for(int i = 0; i < n; i++){
        p[i] = i;
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            np[go1[j]] = p[j];
        }
        for(int j = 0; j < n; j++){
            p[j] = np[j];
        }
        fl = true;
        for(int j = 0; j < n; j++){
            if(p[j] != s[j]){
                fl = false;
                break;
            }
        }
        if(fl){
            if((k - i - 1) % 2 == 0){
                if(i == 0 && k > 1){
                    for(int j = 0; j < n; j++){
                        if(go1[j] != go2[j]){
                            fl = false;
                            break;
                        }
                    }
                    if(!fl){
                        printf("YES\n");
                        return 0;
                    }
                }
                else{
                    printf("YES\n");
                    return 0;
                }
            }
            break;
        }
    }
    for(int i = 0; i < n; i++){
        p[i] = i;
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            np[go2[j]] = p[j];
        }
        for(int j = 0; j < n; j++){
            p[j] = np[j];
        }
        fl = true;
        for(int j = 0; j < n; j++){
            if(p[j] != s[j]){
                fl = false;
                break;
            }
        }
        if(fl){
            if((k - i - 1) % 2 == 0){
                if(i == 0 && k > 1){
                    for(int j = 0; j < n; j++){
                        if(go1[j] != go2[j]){
                            fl = false;
                            break;
                        }
                    }
                    if(!fl){
                        printf("YES\n");
                        return 0;
                    }
                }
                else{
                    printf("YES\n");
                    return 0;
                }
            }
            break;
        }
    }
    printf("NO\n");
    return 0;
}