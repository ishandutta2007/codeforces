#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1100000;

int n, N, m, k;
int num[MAXN];
ll sum[25], same[25];

ll merge(int l, int r, int x){
    if(l == r) return 0;

    int mid = (l + r) / 2;
    ll LHS = merge(l, mid, x+1);
    ll RHS = merge(mid+1, r, x+1);

    ll cnt = 0, mul = 0;
    int pos = mid+1;
    vector<int> V;
    for(int i = l; i <= mid; i++){
        while(pos <= r && num[pos] < num[i]) V.push_back(num[pos++]), mul++;
        V.push_back(num[i]); cnt += mul;
    }
    while(pos <= r) V.push_back(num[pos++]);

    ll scnt = 0, cur = 0;
    for(int i = 0; i < V.size(); i++){
        cur ++;
        if(i == V.size()-1 || V[i+1] != V[i]) scnt += (cur - 1) * cur /2, cur = 0;
    }

    for(int i = l; i <= r; i++){
        num[i] = V[i-l];
    }

    ll tot = LHS + RHS + cnt;
    same[x] += scnt;
    sum[x] += tot;
    return tot;
}

void update(int k){
    int i = n - k;
    ll dif = -sum[i];
    sum[i] = same[i] - sum[i];
    dif += sum[i];
    for(int j = n; j >= i+1; j--) sum[j] = same[j] - sum[j];
    for(int j = i-1; j >= 0; j--) sum[j] += dif;
}


int main(){
    fill(sum, sum+25, 0);
    fill(same, same+25, 0);
    scanf("%d", &n);
    N = (1 << n);
    for(int i = 0; i < N; i++){
        scanf("%d", &num[i]);
    }
    merge(0,N-1,0);
    for(int k = 0; k <= n; k++)
        same[n-k] = 1LL * (1 << (n - k)) * (1LL * (1<<k) * ((1<<k)-1) / 2) - same[n-k];
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &k);
        update(k);
        printf("%I64d\n", sum[0]);
    }

}