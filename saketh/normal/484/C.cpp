#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

string s;
int N, M, K, D;

int *make(){ return (int *)malloc(sizeof(int) * N); }
int *make_ls(){ int *v = make(); for(int i=0; i<N; i++) v[i]=(i+N-1)%N; return v; }
int *make_id(){ int *v = make(); for(int i=0; i<N; i++) v[i] = i; return v; }

int *compose(int *a, int *b){
    int *res = make();
    for(int i=0; i<N; i++) res[i] = b[a[i]];
    return res;
}

int *pow(int *b, int e){
    if(e == 0) return make_id();
    int *db = compose(b, b);
    int *rs = pow(db, e/2);
    free(db);

    if(e%2){
        int *ret = compose(rs, b);
        free(rs);
        return ret;
    }
    return rs;
}

void dsort(){
    int *ds = make_id(), j=0;
    for(int r=0; r<D; r++)
        for(int i=r; i<K; i+=D)
            ds[i] = j++;
    int *ls = make_ls();
   
    int *comb = compose(ds, ls);
    free(ds);
    free(ls);

    int *full = pow(comb, N-K+1);
    free(comb);

    string t = s;
    for(int i=0; i<N; i++)
        t[(full[i]+N-K+1)%N] = s[i];
    s = t;

    free(full);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> s;
    N = s.length();
    
    for(cin >> M; M; M--){
        cin >> K >> D;
        dsort();
        printf("%s\n", s.c_str());
    }

    cout.flush();
    return 0;
}