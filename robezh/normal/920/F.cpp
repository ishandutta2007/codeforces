#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN 300050

int n,m,l,r,t;
int nxt[1000050];
int num[MAXN];
int datM[4 * MAXN];
ll datS[4 * MAXN];
bool prime[1000050];
vector<int> primes;

int get_divisor(int k){
    if(prime[k]) return 2;
    int cnt = 0;
    for(int i = 0; i < primes.size(); i++){
        if(k % primes[i] == 0){
            while(k % primes[i] == 0){
                cnt ++;
                k /= primes[i];
            }
            return nxt[k] * (cnt+1);
        }
    }
}

void set_p_d(){
    fill(prime, prime+1000050, true);
    for(int i = 2; i < 1000050; i++){
        if(prime[i])
            for(int j = i * 2; j < 1000050; j += i){
                prime[j] = false;
            }
    }
    for(int i = 2; i < 1000050; i++) if(prime[i]) primes.push_back(i);
    nxt[1] = 1;
    for(int i = 2; i < 1000050; i++) nxt[i] = get_divisor(i);
}

void init_datS(int l, int r, int x){
    if(l == r){
        datS[x] = num[l];
        return ;
    }

    int mid = (l + r) / 2;
    init_datS(l, mid, x*2+1);
    init_datS(mid+1, r, x*2+2);
    datS[x] = datS[2*x+1] + datS[2*x+2];
}

void init_datM(int l, int r, int x){
    if(l == r){
        datM[x] = num[l];
        return ;
    }
    int mid = (l + r) / 2;
    init_datM(l, mid, x*2+1);
    init_datM(mid+1, r, x*2+2);
    datM[x] = max(datM[x*2+1], datM[x*2+2]);
}

void update(int a, int b, int x, int l, int r){
    if(r < a || b < l) return ;

    int mid = (l + r) / 2;
    if(l == r) {
        datM[x] = nxt[datM[x]], datS[x] = nxt[datS[x]];
        return ;
    }
    if(a <= l && r <= b && datM[x] <= 2){
        return ;
    }
    update(a, b, x*2+1, l, mid);
    update(a, b, x*2+2, mid+1, r);

    datM[x] = max(datM[x*2+1], datM[x*2+2]);
    datS[x] = datS[x*2+1] + datS[x*2+2];
}

ll query(int a, int b, int x, int l, int r){
    if(r < a || b < l) return 0;

    int mid = (l + r) / 2;
    if(a <= l && r <= b) return datS[x];

    ll LHS = query(a, b, x*2+1, l, mid);
    ll RHS = query(a, b, x*2+2, mid+1, r);

    return LHS + RHS;
}

int main(){
    set_p_d();
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    init_datS(0,n-1,0);
    init_datM(0,n-1,0);
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &t, &l, &r);
        l--, r--;
        if(t == 1) update(l,r,0,0,n-1);
        else printf("%I64d\n", query(l,r,0,0,n-1));
    }
}