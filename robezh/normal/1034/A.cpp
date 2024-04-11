#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 500, K = (int)(1e7 + 5e6 + 500),  M = K;
const int INF = (int)1e9;

int p[M],x;
int pm[M], pms;
int n, num[N];
int cnt[K];

void sieve(){
    for(int i = 2; i < M; i++){
        if(!p[i]) p[i] = pm[pms++] = i;
        for(int j = 0; j < pms && i * pm[j] < M; j++){
            p[i * pm[j]] = pm[j];
            if(i % pm[j] == 0) break;
        }
    }
}

int main(){
    sieve();

    scanf("%d", &n);
    int g = 0;
    for(int i = 0; i < n; i++) scanf("%d", &num[i]), g = __gcd(g, num[i]);
    for(int i = 0; i < n; i++) for(int j = num[i] / g; j > 1;) for(++cnt[x=p[j]]; p[j]==x;) j /= p[j];

    int res = 0;
    for(int i = 1; i < K; i++) res = max(res, cnt[i]);
    cout << (res ? n - res : -1) << endl;

}