#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e5 + 500;
const int INF = (int)2e9 + (int)1e7;

int n,s,l;
int num[MAXN], dat[MAXN * 4];
multiset<int> S;

void update(int a, int b, int x, int l, int r, int val){
    if(r < a || b < l) return ;
    int mid = (l + r) / 2;
    if(l == r) {
        dat[x] = val;
        return ;
    }
    update(a, b, x*2+1, l, mid, val);
    update(a, b, x*2+2, mid+1, r, val);

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

void update(int pos, int val){
    update(pos,pos,0,0,n,val);
}

int query(int l, int r){
    return query(l,r,0,0,n);
}

int getnxt(int pos) {
    return S.empty() ? 0 : (max(*(--S.end()), num[pos]) - min(*(S.begin()), num[pos]));
}

int main(){
    fill(dat, dat+MAXN*4, INF);

    scanf("%d%d%d", &n, &s, &l);
    for(int i = 1; i <= n; i++) scanf("%d", &num[i]);
    int pos = 0;
    update(0, 0);
    for(int i = 1; i <= n; i++){
        while(pos+1 <= n && getnxt(pos+1) <= s){
            pos++;
            //cout << i << ' ' << pos << endl;
            S.insert(num[pos]);
            if(pos-i+1 < l) continue;
            int lb = i-1, rb = pos - l;
            int nxtdp = query(lb,rb);
            if(nxtdp+1 < query(pos, pos))
                update(pos,nxtdp+1);
        }
        //cout << S.size() << " ";
        //if(S.size() == 0){pos++; continue;};
        S.erase(S.find(num[i]));
    }
    int res = query(n, n);
    cout << (res == INF ? -1 : res) << endl;
}