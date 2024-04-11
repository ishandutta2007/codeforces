#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long IINF=1e18;

template<typename Monoid>
struct SegmentTree{
    typedef function<Monoid(Monoid,Monoid)> F;
    int n;
    F f;
    Monoid id;
    vector<Monoid> dat;
    SegmentTree(int n_,F f,Monoid id):f(f),id(id){init(n_);}
    void init(int n_){
        n=1;
        while(n<n_) n<<=1;
        dat.assign(n<<1,id);
    }
    void build(const vector<Monoid> &v){
        for (int i=0;i<v.size();++i) dat[i+n]=v[i];
        for (int i=n-1;i;--i) dat[i]=f(dat[i<<1|0],dat[i<<1|1]);
    }
    void update(int k,Monoid x){
        dat[k+=n]=x;
        while(k>>=1) dat[k]=f(dat[k<<1|0],dat[k<<1|1]);
    }
    Monoid query(int a,int b){
        if (a>=b) return id;
        Monoid vl=id,vr=id;
        for (int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
            if (l&1) vl=f(vl,dat[l++]);
            if (r&1) vr=f(dat[--r],vr);
        }
        return f(vl,vr);
    }
    Monoid operator[](int i){
        return dat[i+n];
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    string S; cin >> S;
    auto f=[](ll a,ll b){return min(a,b);};
    SegmentTree<ll> seg(n+1,f,IINF);
    seg.update(0,0);
    for (int i=0;i<n;++i){
        seg.update(i+1,min(seg[i+1],seg[i]+i+1));
        if (S[i]=='1'){
            ll x=seg.query(max(0,i-k),n+1);
            seg.update(min(n,i+1+k),min(seg[min(n,i+1+k)],x+i+1));
        }
    }
    cout << seg[n] << '\n';
}