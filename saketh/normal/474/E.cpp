#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100005
#define hw (y-x+1)/2
using namespace std;
typedef long long ll;

struct seg{
    int m, i;
    seg(int m=0, int i=-1){ this->m = m, this->i = i; }
    seg operator+(const seg &y) const{
        return seg(max(m, y.m), (y.m>m)?y.i:i);
    }
};

int N, D, sto[MAXN];
ll h[MAXN];
vector<pair<ll, int> > sp;
seg tree[(1<<18)+5], res[MAXN];

void ins(int v, int i, int l, int loc=1, int x=0, int y=(1<<17)-1){
    if(l<x || y<l) return;
    if(x == y){ tree[loc] = seg(v, i); return; }
    ins(v, i, l, 2*loc, x, x+hw-1);
    ins(v, i, l, 2*loc+1, x+hw, y);
    tree[loc] = tree[2*loc] + tree[2*loc+1];
}

seg que(int l, int r, int loc=1, int x=0, int y=(1<<17)-1){
    if(r<x || y<l) return seg(0, -1);
    if(l<=x && y<=r) return tree[loc];
    return que(l, r, 2*loc, x, x+hw-1) + que(l, r, 2*loc+1, x+hw, y);
}

void print(int end){
    if(end == -1) return;
    print(res[end].i);
    cout << end+1 << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> D;
    for(int i=0; i<N; i++){
        cin >> h[i];
        sp.push_back(make_pair(h[i], i));
    }

    sort(sp.begin(), sp.end());
    for(int i=0; i<N; i++)
        sto[sp[i].second] = i;

    int b = 0;
    for(int i=0; i<N; i++){
        auto x = lower_bound(sp.begin(), sp.end(), make_pair(h[i]+D, 0));
        if(x != sp.end()) res[i] = res[i] + que(sto[x->second], N-1);
        x = upper_bound(sp.begin(), sp.end(), make_pair(h[i]-D, MAXN));
        if(x != sp.begin()) res[i] = res[i] + que(0, sto[(--x)->second]);
        ins(res[i].m + 1, i, sto[i]);
        if(res[i].m > res[b].m) b = i;
    }
    
    cout << res[b].m+1 << endl;
    print(b);
    cout << endl;    
    return 0;
}