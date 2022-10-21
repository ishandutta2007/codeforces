#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct BinaryIndexedTree{
    vector<T> dat;
    BinaryIndexedTree(int n):dat(n+1,0){}
    void add(int i,T x){
        if (i==0) return;
        for (;i<=dat.size();i+=(i&-i)) dat[i]+=x;
    }
    T sum(int i){
        T res=0;
        for (;i>0;i-=(i&-i)) res+=dat[i];
        return res;
    }
    T query(int l,int r){ //[l,r)
        return sum(r-1)-sum(l-1);
    }
    int lower_bound(T x){
        if (x<=0) return 0;
        int lb=0,r=1;
        while(r<dat.size()) r<<=1;
        for (;r>0;r>>=1){
            if (lb+r<dat.size()&&dat[lb+r]<x){
                x-=dat[lb+r]; lb+=r;
            }
        }
        return lb+1;
    }
    void add0(int i,T x){add(i+1,x);}
    T sum0(int i){return sum(i+1);}
    T query0(int l,int r){return sum(r)-sum(l);}
};

const int MAX=2e5+10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<int> a(n),b(n+1,0),c(n+1,0);
    for (int i=0;i<n;++i){
        cin >> a[i];
        b[i+1]=(a[i]<=m?1:0);
        c[i+1]=(a[i]<=m-1?1:0);
        b[i+1]+=b[i];
        c[i+1]+=c[i];
    }
    for (int i=0;i<=n;++i){
        b[i]=2*b[i]-i+MAX;
        c[i]=2*c[i]-i+MAX;
    }
    BinaryIndexedTree<int> BIT0(MAX*2),BIT1(MAX*2);
    ll ans0=0,ans1=0;
    for (int i=0;i<=n;++i){
        ans0+=BIT0.sum(b[i]);
        ans1+=BIT1.sum(c[i]);
        BIT0.add(b[i],1);
        BIT1.add(c[i],1);
    }
    cout << ans0-ans1 << '\n';
}