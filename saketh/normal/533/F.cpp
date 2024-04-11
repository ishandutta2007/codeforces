#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAXL = 200005;

int N, M;
string A, B;
int succ[MAXL];
bool match[MAXL];

int lap[256];
int mleq[MAXL];

int read_mlap(char c, int l){
    if(lap[c]==-1) return -1;
    return l - lap[c];
}

char mp[256];
bool check_pairs(int m, int i){
    for(char c='a'; c<='z'; c++)
        mp[c] = 0;

    for(char c='a'; c <='z'; c++){
        int l = lap[c];
        if(A[m+i]==c) l=m+i;
        if(l<m) continue;
        
        char b = B[l-m];
        if(mp[c] != 0 && mp[c] != b) return false;
        if(mp[b] != 0 && mp[b] != c) return false;
        mp[c] = b;
        mp[b] = c;
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> A >> B;
    
    memset(lap, 0xff, sizeof(lap));

    // build mleq 
    for(int i=0; i<M; i++){
        mleq[i] = read_mlap(B[i], i);
        lap[B[i]] = i;
    }
    memset(lap, 0xff, sizeof(lap));

    // build partial match table
    succ[0] = -1;
    succ[1] = 0;
    int cnd = 0;

    for(int i=2; i<=M; ){
        if(read_mlap(B[i-1], i-1) == mleq[cnd]){
            lap[B[i-1]] = i-1;
            succ[i++] = ++cnd;
        }
        else if(cnd) {
            for(int j=i-cnd-1; j<i-succ[cnd]-1; j++)
                if(lap[B[j]] == j)
                    lap[B[j]] = -1;    
            cnd = succ[cnd];
        }
        else {
            succ[i++] = 0;
        }
    }

    // find some dank matches
    int TM = 0, i = 0;
    memset(lap, 0xff, sizeof(lap));

    for(int m=0; i+m<N;){
        if(i<M && read_mlap(A[i+m], i+m) == mleq[i] && check_pairs(m, i)){
            if(i == M-1) {
                match[m] = true;
                TM++;    
            }
            lap[A[i+m]] = i+m;
            i = i+1;
        }
        else if(succ[i]>-1){
            m = m + i - succ[i];
            i = succ[i];
        }
        else{
            i = 0;
            m++;
        }

        for(char c='a'; c<='z'; c++)
            if(lap[c] < m) lap[c] = -1;
    }

    printf("%d\n", TM);
    for(int i=0; i<N; i++)
        if(match[i])
            printf("%d ", i+1);
    printf("\n");
    return 0;
}