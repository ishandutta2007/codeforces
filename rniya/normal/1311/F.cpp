#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

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
    int n; cin >> n;
    vector<ll> x(n),v(n);
    for (int i=0;i<n;++i) cin >> x[i];
    for (int i=0;i<n;++i) cin >> v[i];
    vector<ll> compress(n);
    for (int i=0;i<n;++i) compress[i]=v[i];
    sort(compress.begin(),compress.end());
    compress.erase(unique(compress.begin(),compress.end()),compress.end());
    for (int i=0;i<n;++i) v[i]=lower_bound(compress.begin(),compress.end(),v[i])-compress.begin();
    int m=compress.size();
    auto f=[](P a,P b){return P{a.first+b.first,a.second+b.second};};
    SegmentTree<P> seg(m,f,{0,0});
    vector<P> xv;
    for (int i=0;i<n;++i) xv.emplace_back(x[i],v[i]);
    sort(xv.begin(),xv.end());
    for (int i=0;i<n;++i){
        auto p=seg[xv[i].second];
        seg.update(xv[i].second,{p.first+xv[i].first,p.second+1});
    }
    ll ans=0;
    for (int i=0;i<n;++i){
        auto p=seg.query(xv[i].second,m),q=seg[xv[i].second];
        ans+=p.first-xv[i].first*p.second;
        seg.update(xv[i].second,{q.first-xv[i].first,q.second-1});
    }
    cout << ans << '\n';
}