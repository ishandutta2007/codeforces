#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
const LL Q = 1e9 + 9;
const LL MAGIC = 233;
char s[N] , t[N];
int n , m;
LL power[N] , H[26][N] , W[26] , P[26];
int match[26];
void work() {
    int i , j , k;
    scanf("%d%d" , &n , &m);
    scanf("%s%s" , s + 1 , t + 1);
    power[0] = 1;
    for (i = 1 ; i <= n ; ++ i) {
        power[i] = power[i - 1] * MAGIC % Q;
        for (j = 0 ; j < 26 ; ++ j) {
            H[j][i] = H[j][i - 1] * MAGIC % Q;
            if (s[i] == j + 'a')
                H[j][i] = (H[j][i] + 1) % Q;
        }
    }
    for (i = 1 ; i <= m ; ++ i) {
        for (j = 0 ; j < 26 ; ++ j) {
            W[j] = W[j] * MAGIC % Q;
            if (t[i] == j + 'a')
                W[j] = (W[j] + 1) % Q;
        }    
    }
    map<LL , int> bel;            
    for (j = 0 ; j < 26 ; ++ j)
        if (W[j]) {
            bel[W[j]] = j;
            //cout << j << ' ' << W[j] << endl;
        }
    int cnt = 26 - bel.size();
    vector<int> res;
    for (i = 1 ; i + m - 1 <= n ; ++ i) {
        memset(match , -1 , sizeof(match));
        for (j = 0 ; j < 26 ; ++ j) {
            LL x = H[j][i + m - 1] - power[m] * H[j][i - 1] % Q + Q;
            P[j] = x % Q;
        }
        int p = cnt;
        for (j = 0 ; j < 26 ; ++ j) {
            if (P[j]) {
                if (!bel.count(P[j]))
                    break;
                else
                    match[j] = bel[P[j]];
            }
        }
        if (j < 26)
            continue;
        for (j = 0 ; j < 26 ; ++ j)
            if (~match[j] && P[j] && P[match[j]] && match[match[j]] != j)
                break;
        if (j >= 26)
            res.push_back(i);
    }
    printf("%d\n" , (int)res.size());
    for (i = 0 ; i < res.size() ; ++ i)
        printf("%d%c" , res[i] , " \n"[i + 1 == res.size()]);
    
}

int main() {
    work();
    return 0;
}