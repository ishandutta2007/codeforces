#include <bits/stdc++.h>

using namespace std;

typedef __int64 ll;

#define N 100010

ll m, c[N], s, g, r, gg, G, lm[101];

void init(){

    for(int i=1; i<N; i++)  c[i]=1ll*i*i*i;

    for(int i=1; i<N ; i++){
        while(s+c[i]<c[i+1]){
            G++;
            s+=c[i];
            lm[G]=s;
        }
    }
    s=0;

}

void solve(){
    for(g=1; g<=G ; g++)    if(m<lm[g]) break;

    gg=--g;

    for(int i=N-10; gg && i>0; i--)if(c[i]<=m){

        if(m-c[i]<lm[gg-1]){
            m=c[i]-1;
            continue;
        }

        gg--;
        m-=c[i];
        s+=c[i];
        i++;

    }
}

int main(){

    init();

    scanf("%I64d", &m);

    solve();

    printf("%I64d %I64d\n", g, s);

    ///return 7;
}