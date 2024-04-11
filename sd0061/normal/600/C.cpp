#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>
#include <set>
using namespace std;
typedef long long LL;
const int N = 200005;

char s[N] , S[N];
pair<int , string> res;

int cnt[26] , n , tmp[N];

void work() {
    scanf("%s" , s);
    n = strlen(s);
    res.first = 1 << 30;
    for (int i = 0 ; i < n ; ++ i)
        ++ cnt[s[i] - 'a'];
    if (n & 1) {
        for (int i = 0 ; i < 26 ; ++ i)
            if (cnt[i]) {
                -- cnt[i];

                int odd = 0;
                vector<int> V;
                for (int j = 0 ; j < 26 ; ++ j)
                    if (cnt[j] & 1) {
                        V.push_back(j);
                        ++ odd;
                    }
                int times = odd / 2;
                memcpy(tmp , cnt , sizeof(cnt));
                for (int j = 0 ; j < V.size() ; ++ j) {
                    if (j < times)
                        ++ tmp[V[j]];
                    else
                        -- tmp[V[j]];
                }
                int len = 0;
                for (int j = 0 ; j < 26 ; ++ j) {
                    for (int k = 0 ; k < tmp[j] ; k += 2)
                        S[len ++] = 'a' + j;
                }                
                S[len ++] = 'a' + i;
                for (int j = 25 ; j >= 0 ; -- j) {
                    for (int k = 0 ; k < tmp[j] ; k += 2)
                        S[len ++] = 'a' + j;
                }
                S[len] = 0;
                // cout << S << endl;
                res = min(res , make_pair(odd , (string)S));
                
                ++ cnt[i];
            }
    } else {
        int odd = 0;
        vector<int> V;
        for (int j = 0 ; j < 26 ; ++ j)
            if (cnt[j] & 1) {
                V.push_back(j);
                ++ odd;
            }
        int times = odd / 2;
        memcpy(tmp , cnt , sizeof(cnt));
        for (int j = 0 ; j < V.size() ; ++ j) {
            if (j < times)
                ++ tmp[V[j]];
            else
                -- tmp[V[j]];
        }
        int len = 0;
        for (int j = 0 ; j < 26 ; ++ j) {
            for (int k = 0 ; k < tmp[j] ; k += 2)
                S[len ++] = 'a' + j;
        }                
        for (int j = 25 ; j >= 0 ; -- j) {
            for (int k = 0 ; k < tmp[j] ; k += 2)
                S[len ++] = 'a' + j;
        }
        S[len] = 0;
        res = min(res , make_pair(odd , (string)S));

    }
    cout << res.second << endl;    
}

int main() {
    work();
    return 0;
}