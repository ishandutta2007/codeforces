
#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    int val;
    node *L, *R;
    void upd(){
        this->val = min(this->L->val, this->R->val);
    }
};
void build(node *&x, ll l, ll r){
    x = new node();
    if(l == r){
        x->val = 0;
        return;
    }
    ll mid = (l + r)/2;
    build(x->L, l, mid);
    build(x->R, mid +1 , r);
    x->upd();

}
void upd(node *&x, ll l, ll r, ll p, ll a){
    if(p < l || p > r) return;
    if(l == r){
        x->val = a;
        return;
    }
    ll mid = (l + r)/2;
    upd(x->L, l, mid, p, a);
    upd(x->R, mid +1 , r, p, a);
    x->upd();
}
int cnt(node *&x, ll l, ll r, ll a, ll b){
    if(l > b || r < a) return 1e9;
    if(l >= a && r <= b)
        return x ->val;
    ll mid = (l + r)/2;
    return min(cnt(x->L, l, mid,a,b),
                cnt(x->R, mid+1,r,a,b));
}
node *rt;
vector<int> v[500009];
int L[500009], M[500009], F[500009], J[500009], ans[500009], rL[500009];
long long pas = 0;
 main(){
     ios_base::sync_with_stdio(false);
     cin.tie(0);
    int n;
    cin >> n;
    build(rt,1,n);
    int R = 1;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        if(v[a].size() >= 3) R = max(R, v[a][v[a].size()-3] + 1);
        M[i] = R;
         v[a].push_back(i);
        if(v[a].size() >= 3){
            int x = v[a][v[a].size()-2], y = v[a][v[a].size()-3];
            upd(rt, 1, n, i, y);
            upd(rt, 1, n, x, y);
            upd(rt, 1, n, y, y);
            int X = y;
            while(1){
                int X1 = cnt(rt, 1, n, X, i);
                if(X1 == X) break;
                X = X1;
            }

            if(X >= R) L[i] = X;
        }
    }
    for(int i = 1 ;i <= n; i++){
        if(L[i]) J[L[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        if(!L[i]) continue;
        if(!L[L[i]-1]){
            rL[i] = i;
            ans[i] = 1;
        }
        else{
            rL[i] = rL[L[i] - 1];
            ans[i] = ans[L[i] - 1] + 1;
            while(L[rL[i]] < M[i]){
                rL[i] = J[rL[i] + 1];
                ans[i] --;
            }
        }
    }
    for(int i =1; i <= n; i++){
        pas += ans[i];
    }
    cout <<pas<<endl;
}