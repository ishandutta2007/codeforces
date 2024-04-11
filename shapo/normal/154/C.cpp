#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <ctype.h>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

#define maxn 4000000

using namespace std;

struct pr{int a; unsigned long long b;};

pr sm[maxn], sm1[maxn];
int num[maxn], n, m, nm = 0;
const unsigned long long osn = 174628451LL;
unsigned long long hash[maxn];

bool cmp(const pr &a, const pr &b){
    return(a.a < b.a || (a.a == b.a && a.b < b.b));
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i){
        int u, v; scanf("%d%d", &u, &v);
        sm[2 * i - 1].a = sm[2 * i].b = u;
        sm[2 * i - 1].b = sm[2 * i].a = v;
    }

    for(int i = 1; i <= n; ++i){hash[i] = 0; sm[2 * m + i].a = sm[2 * m + i].b = i;}

    sort(sm + 1, sm + 2 * m + n + 1, cmp);
    for(int i = 1; i <= 2 * m + n; ++i)
        if(sm[i].a != sm[i].b){
            ++nm; sm1[nm] = sm[i];
        }

    unsigned long long c_hash = 0;
    long long cur = 0, res = 0;
    for(int i = 1; i <= nm; ++i){
        //printf("sm1[%d] a = %d, b = %d\n", i, sm1[i].a, sm1[i].b);
        c_hash = (c_hash * osn + sm1[i].b);
        if(i == nm || sm1[i].a != sm1[i +1].a){
            hash[sm1[i].a] = c_hash; c_hash = 0;
        }
    }

    sort(hash + 1, hash + n + 1);

    for(int i = 1; i <= n; ++i){
        ++cur;
        if(i == n || hash[i] != hash[i + 1]){
            res = res + (cur - 1) * cur / 2; cur = 0;
        }
    }
    //cout << res << " res\n";
    for(int i = 1; i <= n; ++i)hash[i] = 0;

    c_hash = cur = 0;
    for(int i = 1; i <= 2 * m + n; ++i){
        c_hash = (c_hash * osn + sm[i].b);
        if(i == 2 * m + n || sm[i].a != sm[i + 1].a){
            hash[sm[i].a] = c_hash; c_hash = 0;
        }
    }
    sort(hash + 1, hash + n + 1); cur = 0;
    for(int i = 1; i <= n; ++i){
        ++cur;
        if(i == n || hash[i] != hash[i + 1]){
            res = res + (cur - 1) * cur / 2; cur = 0;
        }
    }

    cout << res << endl;

    return 0;
}