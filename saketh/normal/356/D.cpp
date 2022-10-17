#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
int bag[70500];
int ord[70500];

unsigned int can[2][2300];
int itm[70500];
int cont[70500];
bool outs[70500];
int coins[70500];

unsigned int fetch(int x, int j){
    if(j <= -32) return 0;
    if(j<0) return can[x][0] << abs(j);
    int rem = j%32;
    int sta = j/32, end = sta+1;
    
    unsigned int res = can[x][sta] >> rem;
    
    if(rem) res |= can[x][end] << (32-rem);
    
    return res;
    return (can[x][sta]>>rem) | (can[x][end]<<(32-rem));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> S;
    for(int i=0; i<N; i++){
        cin >> bag[i];
        ord[i] = i;
    }

    sort(ord, ord+N, [](int i, int j){ return bag[i] < bag[j]; });
    if(bag[ord[N-1]] > S){ cout << -1 << endl; return 0; }
    S -= bag[ord[N-1]];

    can[0][0] = 1;

    int x = 0;
    for(int i=0; i<N-1; i++){
        int siz = bag[ord[i]];
        for(int j=0; j<2200; j++){
            can[x^1][j] = can[x][j];
            unsigned int msk = fetch(x, 32*j-siz) | can[x^1][j];
            unsigned int diff = can[x^1][j] ^ msk;
            while(diff){
                int idx = 31-__builtin_clz(diff);
                itm[32*j+idx] = ord[i]+1; 
                diff ^= 1u << idx; 
            }           
            can[x^1][j] = msk;
        }
        x ^= 1;
    }

    while(S) {
        if(!itm[S]){ cout << -1 << endl; return 0; }    
        outs[itm[S]-1] = true;
        S -= bag[itm[S]-1];
    }

    int lst = 0;
    for(int i=0; i<N; i++){
        coins[ord[i]] = bag[ord[i]];
        if(!outs[ord[i]]){
            cont[ord[i]] = lst;
            if(lst) coins[ord[i]] -= bag[lst-1];
            lst = ord[i]+1;
        }
    }

    for(int i=0; i<N; i++){
        cout << coins[i];
        if(cont[i]) cout << " 1 " << cont[i];
        else cout << " 0";
        cout << "\n";
    }
}