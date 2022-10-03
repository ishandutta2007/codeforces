#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<30;
template<typename T>
struct SegmentTree{
    using F=function<T(T,T)>;
    
    int n;
    vector<T> dat;
    F f;
    T ti;
    
    SegmentTree(int n_ ,F f ,T ti) :f(f),ti(ti){
        n=1;
        while(n<n_) n*=2;
        dat.assign(2*n-1,ti);
    }
    
    SegmentTree(int n_ ,vector<T> &v ,F f,T ti) :f(f),ti(ti){
        n=1;
        while(n<n_) n*=2;
        dat.assign(2*n-1,ti);
        
        for(int i=n-1;i-(n-1)<v.size();i++) dat[i]=v[i-(n-1)];
        
        for(int i=n-2;i>=0;i--) dat[i]=f(dat[i*2+1],dat[i*2+2]);
    }
    
    void update(int k,T x){
        k+=n-1;
        dat[k]=x;
        
        while(k){
            k=(k-1)/2;
            dat[k]=f(dat[k*2+1],dat[k*2+2]);
        }
    }
    
    void set(int k,T x){
        dat[n-1+k]=x;
    }
    
    void built(){
        for(int i=n-2;i>=0;i--) dat[i]=f(dat[i*2+1],dat[i*2+2]);
    }
    
    T query_(int a,int b,int k,int l,int r){
        if(r<=a||b<=l) return ti;
        if(a<=l&&r<=b) return dat[k];
        else{
            T vl=query_(a,b,2*k+1,l,(l+r)/2);
            T vr=query_(a,b,2*k+2,(l+r)/2,r);
            return f(vl,vr);
        }
    }
    
    T query(int a,int b){
        return query_(a,b,0,0,n);
    }
    
    T get(int k){
        return dat[k+n-1];
    }
    
    template<typename C>
    int findright(int st,C &check,T &acc,int k,int l,int r){
        if(l+1==r){
            acc=f(acc,dat[k]);
            return check(acc)?k-(n-1):-1;
        }
        int m=(l+r)/2;
        if(m<=st) return findright(st,check,acc,2*k+2,m,r);
        if(st<=l&&!check(f(acc,dat[k]))){
            acc=f(acc,dat[k]);
            return -1;
        }
        int vl=findright(st,check,acc,2*k+1,l,m);
        if(~vl) return vl;
        return findright(st,check,acc,2*k+2,m,r);
    }
    
    template<typename C>
    int findright(int st,C &check){
        T acc=ti;
        return findright(st,check,acc,0,0,n);
    }//idx
    
    template<typename C>
    int findleft(int st,C &check,T &acc,int k,int l,int r){
        if(l+1==r){
            acc=f(acc,dat[k]);
            return check(acc)?k-(n-1):INF;
        }
        int m=(l+r)/2;
        if(m>=st) return findleft(st,check,acc,2*k+1,l,m);
        if(st>=r&&!check(f(acc,dat[k]))){
            acc=f(acc,dat[k]);
            return INF;
        }
        int vr=findleft(st,check,acc,2*k+2,m,r);
        if(vr!=INF) return vr;
        return findleft(st,check,acc,2*k+1,l,m);
    }
    
    template<typename C>
    int findleft(int st,C &check){
        T acc=ti;
        return findleft(st,check,acc,0,0,n);
    }//idx
    
};

set<pair<int,int>> SE[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    SegmentTree<pair<int,int>> seg(N,
                                   [](auto a,auto b){return max(a,b);},
                                   mp(-INF,-1));
    
    vector<int> def(N);
    
    for(int i=0;i<N;i++){
        cin>>def[i];
    }
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        SE[a].insert(mp(b,i));
        SE[b].insert(mp(a,i));
        def[a]--;
        def[b]--;
    }
    
    for(int i=0;i<N;i++){
        seg.set(i,mp(def[i],i));
    }
    seg.built();
    
    vector<int> ans;
    
    while(1){
        auto s=seg.query(0,N);
        if(s.fi<0) break;
        for(auto it:SE[s.se]){
            ans.push_back(it.se);
            SE[it.fi].erase(mp(s.se,it.se));
            seg.update(it.fi,mp(seg.get(it.fi).fi+1,it.fi));
        }
        SE[s.se].clear();
        seg.update(s.se,mp(-INF,s.se));
    }
    
    if(si(ans)==M){
        cout<<"ALIVE\n";
        reverse(all(ans));
        for(int a:ans) cout<<a+1<<" ";
        cout<<"\n";
    }else cout<<"DEAD\n";
}