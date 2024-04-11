#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)2e5 + 500, INF = (int)1e9;

int n,q;
int dat[MAXN * 4];
int num[MAXN];
int las[MAXN];

void init_dat(int l, int r, int x){
    if(l == r){dat[x] = num[l]; return ;}

    int mid = (l + r) / 2;
    init_dat(l, mid, x*2+1);
    init_dat(mid+1, r, x*2+2);
    dat[x] = min(dat[2*x+1], dat[2*x+2]);
}


int query(int a, int b, int x, int l, int r){
    if(r < a || b < l) return INF;

    int mid = (l + r) / 2;
    if(a <= l && r <= b) return dat[x];

    int LHS = query(a, b, x*2+1, l, mid);
    int RHS = query(a, b, x*2+2, mid+1, r);

    return min(LHS, RHS);
}

int main(){
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        if(num[i] == 0) num[i] = INF;
    }
    init_dat(0, n-1, 0);
    fill(las, las+MAXN, -1);
    bool good = true;
    for(int i = 0; i < n; i++){

        if(num[i] != INF && las[num[i]] != -1){
            if(i-1 >= las[num[i]] +1 && query(las[num[i]]+1, i-1, 0, 0, n-1) < num[i]){
                good = false;
                break;
            }
        }
        if(num[i] != INF) las[num[i]] = i;
    }
    if(!good) return !printf("NO");

    bool apq = false;
    for(int i = 0; i < n; i++) if(num[i] == q) apq = true;
    if(!apq){
        bool full = false;
        for(int i = 0; i < n; i++){
            if(num[i] == INF){num[i] = q; full = true; break;}
        }
        if(!full) return !printf("NO");
    }

    for(int i = 1; i < n; i++){
        if(num[i] == INF) num[i] = num[i-1];
    }
    for(int i = n-2; i >= 0; i--){
        if(num[i] == INF) num[i] = num[i+1];
    }
    printf("YES\n");
    for(int i = 0; i < n; i++) printf("%d ", num[i]);

}