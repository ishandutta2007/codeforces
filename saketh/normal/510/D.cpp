#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 305;
const int INF = 0x7f7f7f7f;

int N;
int cards[MAXN];
int costs[MAXN];
int minc[MAXN][1024];

vector<int> factor(int arg) {
    vector<int> res;
    
    for(long long p = 2; p*p <= arg; p++)
        if(arg % p) continue;
        else {
            res.push_back(p);
            while(arg % p == 0) arg /= p;
        }

    if(arg>1) res.push_back(arg);    
    sort(res.begin(), res.end());
    return res;
}

int pick(int i) {
    vector<int> facs = factor(cards[i]);
   
    memset(minc, 0x7f, sizeof(minc));
    int M = (1 << facs.size());
    
    minc[0][M-1] = 0;

    for(int j=0; j<N; j++){
        int mask = 0;
        for(int k=0; k<facs.size(); k++)
            if(cards[j] % facs[k] == 0)
                mask |= 1<<k;

        for(int m=0; m<M; m++)
            if(minc[j][m] == INF) continue;
            else {
                minc[j+1][m] = min(minc[j+1][m], minc[j][m]);
                minc[j+1][m&mask] = min(minc[j+1][m&mask], minc[j][m] + costs[j]);
           }
    }

    if(minc[N][0] == INF) return INF;
    return minc[N][0] + costs[i];
}

int main(){
    cin >> N;
    
    for(int i=0; i<N; i++)
        cin >> cards[i];

    for(int i=0; i<N; i++)
        cin >> costs[i];

    int mc = INF;

    for(int i=0; i<N; i++)
        mc = min(mc, pick(i));    

    cout << ( mc==INF ? -1 : mc ) << endl;
    return 0;
}