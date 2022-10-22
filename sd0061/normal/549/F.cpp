#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300005;
int n , K , a[N] , S[N];
int L[N] , R[N] , s[N] , top;
vector<int> V[1000000];

int range(int l , int v) {
    return upper_bound(V[v].begin() , V[v].end() , l) - V[v].begin();
}

void work() {
    int i , j , k;
    scanf("%d%d" , &n , &K);
    //n = 100000 , K = 100;
    V[0].push_back(0);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        //a[i] = rand();
        s[i] = (s[i - 1] + a[i]) % K;
        V[s[i]].push_back(i);
    }
    top = 0;
    for (i = 1 ; i <= n ; ++ i) {
        while (top && a[i] > a[S[top]])
            R[S[top --]] = i;
        S[++ top] = i;
    }
    while (top)
        R[S[top --]] = i;
    top = 0;
    for (i = n ; i > 0 ; -- i) {
        while (top && a[i] >= a[S[top]])
            L[S[top --]] = i;
        S[++ top] = i;
    }
    while (top)
        L[S[top --]] = i;
    LL res = 0;
    for (i = 1 ; i <= n ; ++ i) {

        //int w = min((R[i] - i) , (i - L[i]));
        if ((i - L[i]) < (R[i] - i)) {
            for (j = L[i] ; j < i ; ++ j) {
                int x = (a[i] + s[j]) % K;
                res += range(R[i] - 1 , x);
                res -= range(i - 1 , x);
            }
        } else {
            for (j = i ; j < R[i] ; ++ j) {
                int x = (s[j] - a[i] % K + K) % K;
                res += range(i - 1 , x);
                res -= range(L[i] - 1 , x);
            }
        }

    }
    printf("%I64d\n" , res - n);
}

int main() {
    work();
    return 0;
}