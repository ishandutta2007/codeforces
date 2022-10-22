#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , b , t[N] , w[N];
LL res[N];
queue<int> Q;

int main() {
    scanf("%d%d" , &n , &b);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d%d" , &t[i] , &w[i]);
    }
    LL T = 0; int i = 0;
    while (i < n || !Q.empty()) {
        if (Q.empty()) {
            T = max(T , (LL)t[i]);
            res[i] = T + w[i];
            T += w[i];
            i ++;
        } else {
            int j = Q.front();
            res[j] = T + w[j];
            Q.pop();
            T += w[j];
        }
        while (i < n && t[i] < T) {
            if (Q.size() < b) {
                Q.push(i);
            } else {
                res[i] = -1;
            }
            ++ i;
        }
    }
    for (int i = 0 ; i < n ; ++ i)
        printf("%lld%c" , res[i] , " \n"[i + 1 == n]);        
    return 0;
}