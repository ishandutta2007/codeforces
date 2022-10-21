#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct RollingHash{
    static const int B1=1007,B2=2009;
    static const int mod1=1000000007,mod2=1000000009;
    vector<long long> hash1,hash2,po1,po2;
    RollingHash(const vector<long long> &vs){init(vs);}
    RollingHash(const string &S){
        vector<long long> vs;
        for (char c:S) vs.emplace_back(c);
        init(vs);
    }
    void init(vector<long long> vs){
        int n=vs.size();
        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        po1.assign(n+1,1);
        po2.assign(n+1,1);
        for (int i=0;i<n;++i){
            hash1[i+1]=(hash1[i]*B1+vs[i])%mod1;
            hash2[i+1]=(hash2[i]*B2+vs[i])%mod2;
            po1[i+1]=po1[i]*B1%mod1;
            po2[i+1]=po2[i]*B2%mod2;
        }
    }
    inline pair<long long,long long> get(int l,int r) const{
        long long res1=hash1[r]+mod1-hash1[l]*po1[r-l]%mod1
                ,res2=hash2[r]+mod2-hash2[l]*po2[r-l]%mod2;
        return {res1>=mod1?res1-mod1:res1,res2>=mod2?res2-mod2:res2};
    }
    inline int LCP(int a,int b) const{
        int len=min((int)hash1.size()-a,(int)hash1.size()-b);
        int lb=0,ub=len;
        while(ub-lb>1){
            int mid=(lb+ub)>>1;
            (get(a,a+mid)==get(b,b+mid)?lb:ub)=mid;
        }
        return lb;
    }
};

template<typename T> vector<T> compress(vector<T> v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    return v;
}

template<typename T> vector<int> dict(vector<T> v){
    vector<T> cv=compress(v);
    int n=v.size();
    vector<int> res(n);
    for (int i=0;i<n;++i)
        res[i]=lower_bound(cv.begin(),cv.end(),v[i])-cv.begin();
    return res;
}

template<typename T>
vector<int> Zalgorithm(const T &s){
    int n=s.size();
    vector<int> z(n);
    z[0]=n;
    int i=1,j=0;
    while(i<n){
        while(i+j<n&&s[j]==s[i+j]) ++j;
        z[i]=j;
        if (j==0){++i; continue;}
        int k=1;
        while(i+k<n&&k+z[k]<j) z[i+k]=z[k],++k;
        i+=k,j-=k;
    }
    return z;
}

template<typename T>
vector<int> LCP(const T &s,const T &t){
    T u(s);
    u.insert(u.begin(),t.begin(),t.end());
    vector<int> Z=Zalgorithm(u);
    for (int &i:Z) i=min(i,(int)t.size());
    return vector<int>(Z.begin()+t.size(),Z.end());
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<string> S(n);
    for (int i=0;i<n;++i) cin >> S[i];
    string all="";
    vector<int> sz(n);
    for (int i=0;i<n;++i){
        all+=S[i];
        sz[i]=S[i].size();
    }
    RollingHash rh(all);
    vector<pair<ll,ll>> hash(n);
    vector<int> sum(n+1,0);
    for (int i=0;i<n;++i){
        sum[i+1]=sum[i]+sz[i];
        hash[i]=rh.get(sum[i],sum[i+1]);
    }
    vector<int> comp=dict(hash);
    int ans=sum[n]+n-1;
    for (int l=0;l<n;++l){
        for (int r=l;r<n;++r){
            vector<int> v;
            for (int k=l;k<=r;++k) v.emplace_back(comp[k]);
            vector<int> lcp=LCP(comp,v);
            int cnt=1;
            for (int k=r+1;k<n;++k){
                if (lcp[k]==r-l+1){
                    ++cnt;
                    k+=r-l;
                }
            }
            if (cnt==1) continue;
            ans=min(ans,sum[n]-(sum[r+1]-sum[l])*cnt+n-1+cnt);
        }
    }
    cout << ans << '\n';
}