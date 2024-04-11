#include <bits/stdc++.h>
using namespace std;

const int V = 7005, N = (int)1e5 + 500;
typedef bitset<V> bs;

int n,q;
bs a[N];
bool bad[V];
bs mob[N], dvs[N];
bool res[10*N];
int r_cnt = 0;

int main(){
    for (int i = 2; i < V; ++i) {
        for (int j = i * i; j < V; j += i * i) {
            bad[j] = true;
        }
    }

    for(int i = 1; i < V; i++){
        for(int j = 1; j < V; j ++){
            dvs[i][j] = (i % j == 0);
        }
        for(int j = 1; j * i < V; j ++){
            if(!bad[j]){
                mob[i][i*j] = true;
            }
        }
    }

    scanf("%d%d", &n, &q);
    for(int i = 0; i < q; i++){
        int k,x,y,z,v;
        scanf("%d", &k);
        if(k == 1 || k == 4) scanf("%d%d", &x, &v);
        else scanf("%d%d%d", &x, &y, &z);
        x--; y--, z--;
        if(k == 1){
            a[x] = dvs[v];
        }
        else if(k == 2){
            a[x] = (a[y] ^ a[z]);
        }
        else if(k == 3){
            a[x] = (a[y] & a[z]);
        }
        else{
            res[r_cnt++] = (a[x] & mob[v]).count() % 2;
        }
    }
    for(int i = 0; i < r_cnt; i++) printf("%d", res[i]);
}