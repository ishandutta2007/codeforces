#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

typedef long long ll;
const int MAXN = 128;
const int MAXM = 20;
const ll INF = 0x7f7f7f7f7f7f7f7f;

int N, M, B, K, T;
ll money[MAXN];
ll monit[MAXN];
int solve[MAXN];
int order[MAXN];

ll minc[1<<MAXM];

int main(){
    cin >> N >> M >> B;
    for(int i=0; i<N; i++){
        cin >> money[i] >> monit[i];
        for(cin >> K; K; K--){
            cin >> T;
            solve[i] |= 1<<(T-1);
        }
        order[i] = i;
    }

    sort(order, order+N, [](int i, int j){ 
        return monit[i] < monit[j]; });    
    
    ll ans = INF;
    memset(minc, 0x7f, sizeof(minc));
    minc[0] = 0;
    int ALL = (1<<M) - 1;

    for(int i=0; i<N; i++){
        int f = order[i];
        for(int m=0; m<ALL; m++)
            minc[m|solve[f]] = min(minc[m|solve[f]], minc[m] + money[f]);
        if(minc[ALL] != INF) ans = min(ans, minc[ALL] + monit[order[i]] * B); 
    }

    cout << (ans == INF ? -1 : ans) << endl;
}