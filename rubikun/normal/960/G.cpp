// from: https://judge.yosupo.jp/submission/26605
 
// verification-helper: PROBLEM https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind
 
#include<bits/stdc++.h>
using namespace std;
 
#define call_from_test
 
#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
 
//BEGIN CUT HERE
template<typename T,T MOD = 1000000007>
struct Mint{
    static constexpr T mod = MOD;
    T v;
    Mint():v(0){}
    Mint(signed v):v(v){}
    Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}
    
    Mint pow(long long k){
        Mint res(1),tmp(v);
        while(k){
            if(k&1) res*=tmp;
            tmp*=tmp;
            k>>=1;
        }
        return res;
    }
    
    static Mint add_identity(){return Mint(0);}
    static Mint mul_identity(){return Mint(1);}
    
    Mint inv(){return pow(MOD-2);}
    
    Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
    Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
    Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
    Mint& operator/=(Mint a){return (*this)*=a.inv();}
    
    Mint operator+(Mint a) const{return Mint(v)+=a;}
    Mint operator-(Mint a) const{return Mint(v)-=a;}
    Mint operator*(Mint a) const{return Mint(v)*=a;}
    Mint operator/(Mint a) const{return Mint(v)/=a;}
    
    Mint operator-() const{return v?Mint(MOD-v):Mint(v);}
    
    bool operator==(const Mint a)const{return v==a.v;}
    bool operator!=(const Mint a)const{return v!=a.v;}
    bool operator <(const Mint a)const{return v <a.v;}
    
    static Mint comb(long long n,int k){
        Mint num(1),dom(1);
        for(int i=0;i<k;i++){
            num*=Mint(n-i);
            dom*=Mint(i+1);
        }
        return num/dom;
    }
};
template<typename T,T MOD> constexpr T Mint<T, MOD>::mod;
template<typename T,T MOD>
ostream& operator<<(ostream &os,Mint<T, MOD> m){os<<m.v;return os;}
//END CUT HERE
#ifndef call_from_test
 
//INSERT ABOVE HERE
signed ABC127_E(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int h,w,k;
    cin>>h>>w>>k;
    using M = Mint<int>;
    
    M ans{0};
    for(int d=1;d<h;d++)
        ans+=M(d)*M(h-d)*M(w)*M(w);
    
    for(int d=1;d<w;d++)
        ans+=M(d)*M(w-d)*M(h)*M(h);
    
    ans*=M::comb(h*w-2,k-2);
    cout<<ans<<endl;
    return 0;
}
/*
 verified on 2019/06/12
 https://atcoder.jp/contests/abc127/tasks/abc127_e
 */
 
signed main(){
    //ABC127_E();
    return 0;
}
#endif
 
 
#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
 
#define call_from_test
#include "../mod/mint.cpp"
#undef call_from_test
 
#endif
//BEGIN CUT HERE
constexpr int bmds(int x){
    const int v[] = {1012924417, 924844033, 998244353,
        897581057, 645922817};
    return v[x];
}
constexpr int brts(int x){
    const int v[] = {5, 5, 3, 3, 3};
    return v[x];
}
 
template<int X>
struct NTT{
    static constexpr int md = bmds(X);
    static constexpr int rt = brts(X);
    using M = Mint<int, md>;
    vector< vector<M> > rts,rrts;
    
    void ensure_base(int n){
        if((int)rts.size()>=n) return;
        rts.resize(n);rrts.resize(n);
        for(int i=1;i<n;i<<=1){
            if(!rts[i].empty()) continue;
            M w=M(rt).pow((md-1)/(i<<1));
            M rw=w.inv();
            rts[i].resize(i);rrts[i].resize(i);
            rts[i][0]=M(1);rrts[i][0]=M(1);
            for(int k=1;k<i;k++){
                rts[i][k]=rts[i][k-1]*w;
                rrts[i][k]=rrts[i][k-1]*rw;
            }
        }
    }
    
    void ntt(vector<M> &as,bool f){
        int n=as.size();
        assert((n&(n-1))==0);
        ensure_base(n);
        
        for(int i=0,j=1;j+1<n;j++){
            for(int k=n>>1;k>(i^=k);k>>=1);
            if(i>j) swap(as[i],as[j]);
        }
        
        for(int i=1;i<n;i<<=1){
            for(int j=0;j<n;j+=i*2){
                for(int k=0;k<i;k++){
                    M z=as[i+j+k]*(f?rrts[i][k]:rts[i][k]);
                    as[i+j+k]=as[j+k]-z;
                    as[j+k]+=z;
                }
            }
        }
        
        if(f){
            M tmp=M(n).inv();
            for(int i=0;i<n;i++) as[i]*=tmp;
        }
    }
    
    vector<M> multiply(vector<M> as,vector<M> bs){
        int need=as.size()+bs.size()-1;
        int sz=1;
        while(sz<need) sz<<=1;
        as.resize(sz,M(0));
        bs.resize(sz,M(0));
        
        ntt(as,0);ntt(bs,0);
        for(int i=0;i<sz;i++) as[i]*=bs[i];
        ntt(as,1);
        
        as.resize(need);
        return as;
    }
    
    vector<int> multiply(vector<int> as,vector<int> bs){
        vector<M> am(as.size()),bm(bs.size());
        for(int i=0;i<(int)am.size();i++) am[i]=M(as[i]);
        for(int i=0;i<(int)bm.size();i++) bm[i]=M(bs[i]);
        vector<M> cm=multiply(am,bm);
        vector<int> cs(cm.size());
        for(int i=0;i<(int)cs.size();i++) cs[i]=cm[i].v;
        return cs;
    }
};
template<int X> constexpr int NTT<X>::md;
template<int X> constexpr int NTT<X>::rt;
//END CUT HERE
#ifndef call_from_test
signed main(){
    return 0;
}
#endif
 
 
#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
 
//BEGIN CUT HERE
template<typename M_>
class Enumeration{
    using M = M_;
protected:
    static vector<M> fact,finv,invs;
public:
    static void init(int n){
        n=min<decltype(M::mod)>(n,M::mod-1);
        
        int m=fact.size();
        if(n<m) return;
        
        fact.resize(n+1,1);
        finv.resize(n+1,1);
        invs.resize(n+1,1);
        
        if(m==0) m=1;
        for(int i=m;i<=n;i++) fact[i]=fact[i-1]*M(i);
        finv[n]=M(1)/fact[n];
        for(int i=n;i>=m;i--) finv[i-1]=finv[i]*M(i);
        for(int i=m;i<=n;i++) invs[i]=finv[i]*fact[i-1];
    }
    
    static M Fact(int n){
        init(n);
        return fact[n];
    }
    static M Finv(int n){
        init(n);
        return finv[n];
    }
    static M Invs(int n){
        init(n);
        return invs[n];
    }
    
    static M C(int n,int k){
        if(n<k||k<0) return M(0);
        init(n);
        return fact[n]*finv[n-k]*finv[k];
    }
    
    static M P(int n,int k){
        if(n<k||k<0) return M(0);
        init(n);
        return fact[n]*finv[n-k];
    }
    
    // put n identical balls into k distinct boxes
    static M H(int n,int k){
        if(n<0||k<0) return M(0);
        if(!n&&!k) return M(1);
        init(n+k);
        return C(n+k-1,n);
    }
};
template<typename M>
vector<M> Enumeration<M>::fact=vector<M>();
template<typename M>
vector<M> Enumeration<M>::finv=vector<M>();
template<typename M>
vector<M> Enumeration<M>::invs=vector<M>();
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
    return 0;
}
#endif
 
#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
 
#define call_from_test
#include "../combinatorics/enumeration.cpp"
#undef call_from_test
 
#endif
// http://beet-aizu.hatenablog.com/entry/2019/09/27/224701
//BEGIN CUT HERE
template<typename M_>
struct FormalPowerSeries : Enumeration<M_> {
    using M = M_;
    using super = Enumeration<M>;
    using super::fact;
    using super::finv;
    using super::invs;
    
    using Poly = vector<M>;
    using Conv = function<Poly(Poly, Poly)>;
    Conv conv;
    FormalPowerSeries(Conv conv):conv(conv){}
    
    Poly pre(const Poly &as,int deg){
        return Poly(as.begin(),as.begin()+min((int)as.size(),deg));
    }
    
    Poly add(Poly as,Poly bs){
        int sz=max(as.size(),bs.size());
        Poly cs(sz,M(0));
        for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];
        for(int i=0;i<(int)bs.size();i++) cs[i]+=bs[i];
        return cs;
    }
    
    Poly sub(Poly as,Poly bs){
        int sz=max(as.size(),bs.size());
        Poly cs(sz,M(0));
        for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];
        for(int i=0;i<(int)bs.size();i++) cs[i]-=bs[i];
        return cs;
    }
    
    Poly mul(Poly as,Poly bs){
        return conv(as,bs);
    }
    
    Poly mul(Poly as,M k){
        for(auto &a:as) a*=k;
        return as;
    }
    
    // F(0) must not be 0
    Poly inv(Poly as,int deg);
    
    // not zero
    Poly div(Poly as,Poly bs);
    
    // not zero
    Poly mod(Poly as,Poly bs);
    
    // F(0) must be 1
    Poly sqrt(Poly as,int deg);
    
    Poly diff(Poly as);
    Poly integral(Poly as);
    
    // F(0) must be 1
    Poly log(Poly as,int deg);
    
    // F(0) must be 0
    Poly exp(Poly as,int deg);
    
    // not zero
    Poly pow(Poly as,long long k,int deg);
    
    // x <- x + c
    Poly shift(Poly as,M c);
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
    return 0;
}
#endif
 
#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
 
#define call_from_test
#include "enumeration.cpp"
#include "../formalpowerseries/base.cpp"
#undef call_from_test
 
#endif
//BEGIN CUT HERE
template<typename M_>
struct Stirling1st : FormalPowerSeries<M_>{
    using M = M_;
    using super = FormalPowerSeries<M>;
    using Poly = typename super::Poly;
    using super::super, super::fact, super::finv, super::mul;
    
    Poly rs;
    void build(int n){
        super::init(n+1);
        if(n==0){
            rs={M(1)};
            return;
        }
        int m=1;
        rs=Poly({M(0),M(1)});
        for(int e=31-__builtin_clz(n)-1;e>=0;e--){
            Poly as(m+1),bs(m+1);
            for(int i=0;i<=m;i++) as[i]=fact[i]*rs[i];
            bs[m-0]=M(1);
            for(int i=1;i<=m;i++) bs[m-i]=bs[m-(i-1)]*-M(m);
            for(int i=0;i<=m;i++) bs[m-i]*=finv[i];
            Poly cs=mul(as,bs);
            Poly ds(m+1);
            for(int i=0;i<=m;i++) ds[i]=finv[i]*cs[m+i];
            rs=mul(rs,ds);
            m<<=1;
            if((n>>e)&1){
                Poly ts(m+1+1,M(0));
                for(int i=0;i<=m;i++){
                    ts[i+0]+=rs[i]*-M(m);
                    ts[i+1]+=rs[i];
                }
                rs=ts;
                m|=1;
            }
        }
        assert(m==n);
    }
    
    M operator[](int k)const{return rs[k];}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
    return 0;
}
#endif
 
#undef call_from_test
 
const int mod=998244353;
const int MAX=500005;
typedef long long ll;
 
ll inv[MAX],fac[MAX],finv[MAX];
 
void make(){
    
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    
    for(int i=2;i<MAX;i++){
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        fac[i]=fac[i-1]*(ll)i%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
    
}
 
ll comb(ll a,ll b){
    if(a<b) return 0;
    return fac[a]*(finv[b]*finv[a-b]%mod)%mod;
}
 
ll perm(ll a,ll b){
    if(a<b) return 0;
    return fac[a]*finv[a-b]%mod;
}
 
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n,a,b;
    cin>>n>>a>>b;
    if(n==1){
        if(a==1&&b==1) cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    
    n--;
    int k=(n-(a-1)-(b-1));
    
    if(a==0||b==0||k<0){
        cout<<0<<endl;
        return 0;
    }
    
    NTT<2> ntt;
    using M = NTT<2>::M;
    auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
    Stirling1st<M> ss(conv);
    
    ss.build(n);
    make();
    Mint ans=ss[n-k];
    if((n^(n-k))&1) ans=-ans;
    ans*=comb(a-1+b-1,a-1);
    
    cout<<ans<<endl;
    
    return 0;
}