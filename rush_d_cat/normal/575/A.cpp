#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000 + 10;
ll mod;
struct matrix{
    ll a[2][2];
    matrix(){memset(a,0,sizeof(a));}
    void init(){
        a[0][0] = a[1][1] = 1;
    }
    matrix operator * (const matrix &B){
        matrix C;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    C.a[i][j] += a[i][k] * B.a[k][j] % mod;
                }
                C.a[i][j] %= mod;
            }
        }
        return C;
    }
    matrix operator ^ (ll k){
        matrix res, A = (*this);
        res.init();
        while(k){
            if(k&1) res = res * A;
            A = A * A;
            k >>= 1;
        }
        return res;
    }
    void print(){
        cout<<"----"<<endl;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++) cout<<a[i][j]<<' '; cout<<endl;
        }
    }
} val[N<<2];
int s[N];
matrix get(int l){
    matrix r;
    r.a[0][1] = s[l], r.a[1][1] = s[l+1];
    r.a[0][0] = 0, r.a[1][0] = 1;
    return r;
}
void build(int k,int l,int r){
    if(l==r){
        val[k] = get(l);
        return;
    }
    int mid = (l + r) >> 1;
    build(k<<1,l,mid), build(k<<1|1,mid+1,r);
    val[k] = val[k<<1] * val[k<<1|1];
}
void update(int k,int l,int r,int x,int id,int v){
    if(x<0) return;
    if(l==r){
        if(id==-1) val[k] = get(l);
        else val[k].a[id][1] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if(x<=mid) update(k<<1,l,mid,x,id,v);
    else update(k<<1|1,mid+1,r,x,id,v);
    val[k] = val[k<<1] * val[k<<1|1];
}
matrix query(int k,int l,int r,int L,int R){
    if(l==L&&r==R){
        return val[k];
    }
    int mid = (l + r) >> 1;
    if(R<=mid) return query(k<<1,l,mid,L,R);
    if(mid+1<=L) return query(k<<1|1,mid+1,r,L,R);
    return query(k<<1,l,mid,L,mid) * query(k<<1|1,mid+1,r,mid+1,R);
}
struct node{
    int x,id,v;
};
map<ll,vector<node> > upd;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll k; cin>>k>>mod;
    int n,m; cin>>n;
    for(int i=0;i<n;i++) cin>>s[i];
    s[n] = s[0];
    cin>>m;
    upd[k/n].push_back({0,-1,0});
    while(m--){
        ll j,v; cin>>j>>v;
        upd[j/n].push_back({j%n,0,v});
        j--;
        if(j<0) continue;
        upd[j/n].push_back({j%n,1,v});
    }
    build(1,0,n-1);
    matrix X = val[1];
    matrix A; A.init();
    ll pre = -1;
    for(auto i: upd){
        A = A * (X ^ (min(i.first,k/n)-pre-1));
        if(i.first<k/n){
            for(auto j: i.second) update(1,0,n-1,j.x,j.id,j.v);
            A = A * val[1];
            for(auto j: i.second) update(1,0,n-1,j.x,-1,j.v);
        }
        else if(i.first==k/n){
            for(auto j: i.second) update(1,0,n-1,j.x,j.id,j.v);
            if(k%n==0) break;
            A = A * query(1,0,n-1,0,k%n-1);
            break;
        }
        else{
            assert(0);
        }
        pre = i.first;
    }
    cout<<A.a[1][0]<<endl;
}
/*
4 8
3
1 2 1
2
7 3
5 4

*/