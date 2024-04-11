#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 400500;
const ll INF = (ll)5e17 + 500;

int nxt[20][MAXN];
ll nxt_sum[20][MAXN];
ll w[MAXN];
ll Q,k,p,q;
ll last = 0,R,W;
int cnt = 1;

void add(int index, ll we){
    cnt++;
    w[cnt] = we;

    int from;
    if(w[index] >= w[cnt]){
        nxt[0][cnt] = index;
    }
    else{
        from = index;
        for(int i = 19; i >= 0; i--){
            if(w[nxt[i][from]] < w[cnt]){
                from = nxt[i][from];
            }
        }
        nxt[0][cnt] = nxt[0][from];
    }

    nxt_sum[0][cnt] = nxt[0][cnt] == 0 ? INF: w[nxt[0][cnt]];
    for(int i = 1; i < 20; i++){
        nxt[i][cnt] = nxt[i-1][nxt[i-1][cnt]];
        nxt_sum[i][cnt] = nxt[i][cnt] == 0 ? INF : nxt_sum[i-1][cnt] + nxt_sum[i-1][nxt[i-1][cnt]];
    }
}

ll query(int index, ll x){
    ll ans = 1;
    for(int i = 19; i >= 0; i--){
        if(nxt_sum[i][index] <= x){
            ans += (1<<i);
            x -= nxt_sum[i][index];
            index = nxt[i][index];
        }
    }
    return ans;
}


int main(){
    for(int i = 0; i < 20; i++){
        fill(nxt[i],nxt[i]+MAXN,0);
        fill(nxt_sum[i],nxt_sum[i]+MAXN,INF);
    }
    w[0] = INT_MAX;

    scanf("%I64d", &Q);
    while(Q--){
        scanf("%I64d%I64d%I64d", &k, &p, &q);
        R = p ^ last, W = q ^ last;
        if(k == 1) add(R,W);
        else{
            if(W < w[R]) last = 0;
            else last = query(R, W-w[R]);
            printf("%I64d\n", last);
        }
        //cout << "cnt = " << cnt << endl;
    }
}