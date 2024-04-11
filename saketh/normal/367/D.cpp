#include <iostream>
using namespace std;

const int MAXN = 100005;
const int MAXM = 20;

int N, M, D, S, V;
int grp[MAXN];
int num[MAXM];
bool bad[1<<MAXM];

void mark(int m){
    if(bad[m]) return;
    bad[m] = true;
    for(int i=0; i<M; i++)
        if((m>>i)&1)
            mark(m ^ (1<<i));
}

int main(){
    cin >> N >> M >> D;
    for(int i=0; i<M; i++){
        cin >> S;
        for(int j=0; j<S; j++){
            cin >> V;
            grp[V-1] = i;
        }
    }

    int m = 0;
    for(int i=0; i<N; i++){
        if(i-D >= 0){
            int g = grp[i-D];
            num[g]--;
            if(num[g] == 0) m ^= (1<<g);
        }

        int g = grp[i];
        if(!num[g]) m ^= (1<<g);
        num[g]++;

        if(i >= D-1) mark((1<<M)-1-m);
    }

    int ans = M;
    for(int i=0; i<(1<<M); i++)
        if(!bad[i])
            ans = min(ans, __builtin_popcount(i));
    cout << ans << endl;
    return 0;
}