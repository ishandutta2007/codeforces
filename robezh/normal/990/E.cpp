#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6;
const ll INF = (ll)1e18;

int n,m,k,a;
int num[N], las[N];
bool ocu[N];

ll get(int l){
    int now = 0;
    int cnt = 0;
    while(true){
        int nxt = now + l;
        if(nxt < n && ocu[nxt]) nxt = las[nxt];
        if(nxt == now) return INF;
        now = nxt;
        cnt ++;
        if(nxt >= n) return 1LL * cnt * num[l];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> a;
        ocu[a] = true;
    }
    for(int i = 1; i <= k; i++) cin >> num[i];
    if(ocu[0]) return !printf("-1");
    int last = las[0] = 0;
    for(int i = 1; i < n; i++){
        if(!ocu[i]) last = i;
        las[i] = last;
    }
    ll res = INF;
    for(int i = 1; i <= k; i++){
        res = min(res, get(i));
    }
    if(res == INF) cout << -1;
    else cout << res;

}