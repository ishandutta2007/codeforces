#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cctype>
using namespace std;
typedef long long LL;
const int N = 10005;
const int M = 200005;
int n , X[N] , Y[N];
int p[N] , q[N];
int a[N] , b[N] , c[30] , d[30];
vector<int> baseA , baseB;
bool f[N] , g[N];
vector< pair<int , int> > resA;
vector< pair<int , int> > resB;
map<int , int> hashA , hashB;

void work() {
    int i , j , k , x , y;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&X[i]);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&Y[i]);
    memcpy(a , X , sizeof(a));
    memset(p , -1 , sizeof(p));
    memset(c , -1 , sizeof(c));
    for (j = 29 ; j >= 0 ; -- j) {
        x = -1;
        for (i = 0 ; i < n ; ++ i)
            if (!~p[i] && (a[i] >> j & 1)) {
                x = i;
                break;
            }
        if (!~x) continue; p[x] = j , c[j] = x;
        for (i = 0 ; i < n ; ++ i)
            if ((x != i) && (a[i] >> j & 1)) {
                a[i] ^= a[x];
                resA.push_back(make_pair(i , x));
            }
    }
    for (i = 0 ; i < n ; ++ i)
        if (a[i]) {
            baseA.push_back(a[i]);
            hashA[a[i]] = i;
        }
    memcpy(b , Y , sizeof(b));
    memset(q , -1 , sizeof(q));
    memset(d , -1 , sizeof(d));
    for (j = 29 ; j >= 0 ; -- j) {
        x = -1;
        for (i = 0 ; i < n ; ++ i)
            if (!~q[i] && (b[i] >> j & 1)) {
                x = i;
                break;
            }
        if (!~x) continue; q[x] = j , d[j] = x;
        for (i = 0 ; i < n ; ++ i)
            if ((x != i) && (b[i] >> j & 1)) {
                b[i] ^= b[x];
                resB.push_back(make_pair(i , x));
            }
    }
    for (i = 0 ; i < n ; ++ i)
        if (b[i]) {
            baseB.push_back(b[i]);
            hashB[b[i]] = i;
        }
    sort(baseA.begin() , baseA.end() , greater<int>());
    sort(baseB.begin() , baseB.end() , greater<int>());
//    for (i = 0 ; i < baseA.size() ; ++ i)
//        printf("%d%c" , baseA[i] , " \n"[i + 1 == baseA.size()]);
//    for (i = 0 ; i < baseB.size() ; ++ i)
//        printf("%d%c" , baseB[i] , " \n"[i + 1 == baseB.size()]);

    for (j = 0 ; j < baseB.size() ; ++ j) {
        x = baseB[j];
        for (k = 29 ; k >= 0 ; -- k) {
            if (x >> k & 1) {
                for (i = 0 ; i < baseA.size() ; ++ i)
                    if (baseA[i] >> k & 1) {
                        x ^= baseA[i];
                        if (!f[i] && !g[j]) {
                            f[i] = g[j] = 1;
                            int L = hashA[baseA[i]]; // L -> R
                            int R = hashB[baseB[j]];
                            if (L != R) {
                                resA.push_back(make_pair(L , R)) , a[L] ^= a[R];
                                resA.push_back(make_pair(R , L)) , a[R] ^= a[L];
                                resA.push_back(make_pair(L , R)) , a[L] ^= a[R];
                                hashA[a[L]] = L;
                                hashA[a[R]] = R;
                                swap(p[L] , p[R]);
                                c[p[L]] = L;
                                c[p[R]] = R;
                            }
                            //cout << "papa : " << L << ' ' << R << endl;
                        }
                        break;
                    }
            }
        }
        if (x)
            break;
    }
    if (j < baseB.size()) {
        puts("-1");
        return;
    }

//    for (i = 0 ; i < n ; ++ i)
//        printf("%d%c" , a[i] , " \n"[i + 1 == n]);
//    for (i = 0 ; i < n ; ++ i)
//        printf("%d%c" , b[i] , " \n"[i + 1 == n]);
    // a -> b

    for (k = 29 ; k >= 0 ; -- k) {
        if (!~c[k]) continue;

        i = c[k];
        for (i = 0 ; i < n ; ++ i)
            if (i != c[k] && ((a[i] ^ b[i]) >> k & 1)) {
                resA.push_back(make_pair(i , c[k]));
                a[i] ^= a[c[k]];
            }
        i = c[k];
        if ((a[i] ^ b[i]) >> k & 1) {
            resA.push_back(make_pair(i , i));
            a[i] ^= a[i];
        }
    }

//    puts("****************");
//    for (i = 0 ; i < n ; ++ i)
//        printf("%d%c" , a[i] , " \n"[i + 1 == n]);
//    for (i = 0 ; i < n ; ++ i)
//        printf("%d%c" , b[i] , " \n"[i + 1 == n]);
//    puts("****************");
    cout << resA.size() + resB.size() << endl;
    for (i = 0 ; i < resA.size() ; ++ i) {
        printf("%d %d\n" , resA[i].first + 1 , resA[i].second + 1);
        X[resA[i].first] ^= X[resA[i].second];
    }
    reverse(resB.begin() , resB.end());
    for (i = 0 ; i < resB.size() ; ++ i) {
        printf("%d %d\n" , resB[i].first + 1 , resB[i].second + 1);
        X[resB[i].first] ^= X[resB[i].second];
    }
//    puts("****************");
//    for (i = 0 ; i < n ; ++ i)
//        printf("%d%c" , X[i] , " \n"[i + 1 == n]);
//    for (i = 0 ; i < n ; ++ i)
//        printf("%d%c" , Y[i] , " \n"[i + 1 == n]);
}

int main() {
    work();
    return 0;
}