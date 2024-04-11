#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)5e5 + 500;

int n,k,d;
bool dat[MAXN * 4];
int num[MAXN];

void update(int a, int b, int x, int l, int r){
    if(r < a || b < l) return ;
    int mid = (l + r) / 2;
    if(l == r) {
        dat[x] = 1;
        return ;
    }
    update(a, b, x*2+1, l, mid);
    update(a, b, x*2+2, mid+1, r);

    dat[x] = dat[2*x+1] | dat[2*x+2];
}

bool query(int a, int b, int x, int l, int r){
    if(r < a || b < l) return 0;

    int mid = (l + r) / 2;
    if(a <= l && r <= b) return dat[x];

    bool LHS = query(a, b, x*2+1, l, mid);
    bool RHS = query(a, b, x*2+2, mid+1, r);

    return LHS | RHS;
}

int main(){
    scanf("%d%d%d", &n, &k, &d);
    for(int i = 0; i < n; i++){scanf("%d", &num[i]);}
    sort(num, num+n);

    for(int i = 0; i < n; i++){
        int lb = (int)(lower_bound(num, num+i, num[i]-d) - num);
        lb --;
        int rb = i - k;
        //cout << "i = " << i << ": " << lb << " " << rb << endl;
        if(lb > rb) continue;
        if(lb == -1) update(i,i,0,0,n-1);
        else{
            bool now = query(lb,rb,0,0,n-1);
            if(now) update(i,i,0,0,n-1);
        }
    }
    //for(int i = 0; i < n; i++) cout << query(i,i,0,0,n-1) << " ";
    if(query(n-1,n-1,0,0,n-1)) printf("YES");
    else printf("NO");
}