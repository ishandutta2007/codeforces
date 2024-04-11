#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int q;
ll t,x,k;
ll pow2[63], lmost[63];

void init(){
    ll res = 1;
    for(int i = 0; i < 62; i++) lmost[i] = pow2[i] = res, res <<= 1;
}

void q1(ll x, ll k){
    int level = 0;
    while(pow2[level+1] <= x){level++;}
    lmost[level] = (-k + lmost[level] + pow2[level]) % pow2[level] + pow2[level];
}

void q2(ll x, ll k){
    int level = 0;
    while(pow2[level+1] <= x){level++;}
    while(level < 62)
        lmost[level] = (-k + lmost[level] + pow2[level]) % pow2[level] + pow2[level],
                k = (k+pow2[level])%pow2[level]*2,
                level++;
}

void q3(ll x){
    int level = 0;
    ll curloc = 0;
    while(pow2[level+1] <= x){level++;}
    curloc = (x - lmost[level] + pow2[level]) % pow2[level];
    while(level >= 0){
        //cout << lmost[level] << " ";
        ll now = (curloc + lmost[level]) % pow2[level] + pow2[level];
        printf("%I64d ", now);
        level--;
        curloc /= 2;
    }
    printf("\n");
}


int main(){
    init();
    scanf("%d", &q);
    while(q--){
        scanf("%I64d", &t);
        if(t == 1){scanf("%I64d%I64d", &x, &k); q1(x,k);}
        else if(t == 2){scanf("%I64d%I64d", &x, &k); q2(x,k);}
        else {scanf("%I64d", &x); q3(x);}
    }
}