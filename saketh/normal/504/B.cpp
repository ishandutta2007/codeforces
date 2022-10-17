#include <cstdio>
#include <string.h>
using namespace std;

const int MAXN = 200005;

int bit[MAXN];

int read(int k){
    int sum = 0;
    while(k > 0){
        sum += bit[k];
        k -= (k & -k);
    }
    return sum;
}

void update(int i, int v){
    while(i < MAXN){
        bit[i]+=v;
        i += (i & -i);
    }
}

int N, p[MAXN], q[MAXN];
int sum[MAXN];

void proc(int v[MAXN]){
    for(int i=0; i<N; i++){
        update(v[i]+1, 1);
        sum[i] += v[i] + 1 - read(v[i]+1);
    }
}

bool used(int v){ return (read(v+1) - read(v))> 0; }

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", p+i);
    for(int i=0; i<N; i++)
        scanf("%d", q+i);

    proc(p);
    memset(bit, 0, sizeof(bit));
    proc(q);   
    memset(bit, 0, sizeof(bit));

    for(int i=0; i<N; i++){
        int j = N-i-1;

        if(sum[j] > i){
            sum[j] -= (i+1);
            if(j>0) sum[j-1]++;
        }
    }

    for(int i=0; i<N; i++){
        int lo = 0, hi = N-1;
        while(lo != hi){
            int mi = (lo + hi)/2;

            int bt = mi - read(mi); 
            if(bt <= sum[i]){
                if(bt == sum[i] && !used(mi)){ lo = mi; hi = mi; }
                else lo = mi + 1;
            }
            else{
                hi = mi - 1;
            }
        } 
        printf("%d ", lo);  
        update(lo+1, 1); 
    }

    printf("\n");
    return 0;
}