#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

int q,t,x,k,s;
bool p[N], exi[N];
vector<int> bit[N], primes;
int pw2[20];

void add_bit(int i, int x){
    while(x <= (N-1)/i){bit[i][x] += 1; x += (x&-x);}
}

int get_bit(int i, int x){
    if(x <= 0) return 0;
    int ans = 0;
    while(x){ans += bit[i][x]; x -= (x&-x);}
    return ans;
}

int get_bit(int i, int l, int r){
    if(l > r) return 0;
    return get_bit(i, r) - get_bit(i, l-1);
}

void add(int x){
    if(exi[x]) return ;
    exi[x] = true;

    int i;
    for(i = 1; i * i < x; i++){
        if(x % i == 0){add_bit(x/i,i); add_bit(i,x/i);}
    }
    if(i * i == x) add_bit(i, i);
}

int query(int x, int k, int s){
    if(x % k != 0) return -1;
    int r = (s - x) / k;
    if(get_bit(k,r) == 0) return -1;

    int curi = 17, now = 0;

    while(curi >= 0){
        if((pw2[curi] & x) == 0){
            int nl = (now + pw2[curi] + k-1) / k, nr = (now + pw2[curi+1] - 1) / k;
            nl = max(nl, 1), nr = min(nr, r);
            if(get_bit(k, nl, nr) > 0){now += pw2[curi];}
        }
        else{
            int nl = (now + k-1) / k, nr = (now + pw2[curi] - 1) / k;
            nl = max(nl, 1), nr = min(nr, r);
            if(get_bit(k, nl, nr) == 0){now += pw2[curi];}
        }
        curi --;
    }
    return now;
}

int main() {
    fill(p, p+N, true);
    for(int i = 2; i <= N; i++){
        if(p[i]) for(int j = 2*i; j <= N; j += i) p[j] = false;
    }
    for(int i = 2; i <= N; i++) if(p[i]) primes.push_back(i);
    for(int i = 1; i <= (N-500); i++){
        for(int j = 0; j < N / i + 2; j++) bit[i].push_back(0);
    }
    pw2[0] = 1;
    for(int i = 1; i < 20; i++) pw2[i] = 2 * pw2[i-1];


    scanf("%d", &q);
    while(q--){
        scanf("%d", &t);
        if(t == 1){scanf("%d", &x); add(x);}
        else{
            scanf("%d%d%d", &x, &k, &s);
            printf("%d\n", query(x,k,s));
        }
    }
}