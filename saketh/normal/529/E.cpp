#include <iostream>
#include <set>
using namespace std;

const int MAXN = 5005;

int N, K, Q, A;
int denom[MAXN];
set<int> all;

int res(){
    int low = K+1;
    
    for(int i=0; i<N; i++){
        for(int u=1; u<=K; u++){
            for(int v=0; u+v<=K; v++){
                int R = A - denom[i] * u;
                
                if(v == 0){
                    if(R == 0) low = min(low, u);
                    continue;
                }

                if(R % v != 0) continue;
                if(!all.count(R/v)) continue;
                low = min(low, u+v);
            }
        }
    }

    if(low == K+1) return -1;
    return low;
}

int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> denom[i];
        all.insert(denom[i]);
    }

    cin >> Q;
    for(int i=0; i<Q; i++){
        cin >> A;
        cout << res() << endl;
    }    
}