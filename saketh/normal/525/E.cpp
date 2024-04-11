#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
const int MAXN = 30;

ll N, K, S;
ll v[MAXN];
ll fact[MAXN];

map<ll, int> ct[2][MAXN];

void go(int w, int i, int j){
    ct[w][0][0] = 1;
    if(i>j) return;    

    int k = j-i+1;

    for(int m=1; m<(1<<k); m++){
        for(int n=m; n>=0; n--){
            n &= m;
            int f = __builtin_popcount(n);

            bool over = false;
            ll sum = 0;
            for(int l=i; l<=j; l++){
                int o = l-i;
                if(((m>>o)&1) == 0) continue;
                if(((n>>o)&1) == 0){
                    sum += v[l];
                }
                else{
                    if(v[l] > 20) over = true;
                    else sum += fact[v[l]];
                }
            }

            if(!over) ct[w][f][sum]++;
        }
    }
}

int main(){
    fact[0] = 1;
    for(int i=1; i<MAXN; i++)
        fact[i] = i * fact[i-1];

    cin >> N >> K >> S;
    for(int i=0; i<N; i++)
        cin >> v[i];

    int mp = N/2;

    go(0, 0, mp);
    go(1, mp+1, N-1);

    ll ans = 0;
    for(int k1=0; k1<=K; k1++){
        for(auto p : ct[0][k1]){
            ll S2 = S - p.first;
            if(S2 < 0) continue;

            for(int k2=0; k1+k2<=K; k2++)
                ans += p.second * ct[1][k2][S2];
        }
    }

    cout << ans << endl;    
}