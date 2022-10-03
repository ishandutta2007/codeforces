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
const int mod1=998244353,mod2=1000000009,MAX=300005;
const ll INF=1LL<<60;

ll ba1,ba2;

struct Rollinghash{
    string S;
    int n;
    int base1;
    int base2;
    vector<ll> h1,h2,ru1,ru2;
    
    void make(string &T,int ba1,int ba2){
        S=T;
        n=S.size();
        
        h2.assign(n+11,0);
        
        ru2.assign(n+11,0);
        
        base2=ba2;
        
        ru2[0]=1;
        
        for(int i=1;i<=n;i++){
            
            
            h2[i]=h2[i-1]*base2+ll(S[i-1]-'a');
            h2[i]%=mod2;
            
            ru2[i]=ru2[i-1]*base2%mod2;
        }
    }
    
    ll ha(int l,int r){
        ll res=(h2[r]-h2[l]*ru2[r-l]%mod2);
        if(res<0) res+=mod2;
        return res;
    }//
};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//unordered_map<ll,vector<int>,custom_hash> MA[11];
//unordered_map<ll,int,custom_hash> sav[11];
map<ll,vector<int>> MA[11];
map<ll,int> sav[11];

vector<int> Zalgo(string S){
    vector<int> A(S.size());
    int c=0;
    for(int i=1;i<S.size();i++){
        if(i+A[i-c]<c+A[c]){
            A[i]=A[i-c];
        }else{
            int j=max(0,c+A[c]-i);
            while(i+j<S.size()&&S[j]==S[i+j]) j++;
            A[i]=j;
            c=i;
        }
    }
    A[0]=S.size();
    
    return A;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    ba1=rng();
    ba2=rng();
    
    string S;cin>>S;
    Rollinghash ro;
    ro.make(S,ba1,ba2);
    
    int N=si(S);
    
    reverse(all(S));
    
    auto Z=Zalgo(S);
    
    reverse(all(S));
    
    for(int i=0;i<N;i++){
        for(int len=1;len<=10;len++){
            int l=i-len+1,r=i+1;
            if(l<0) continue;
            int y=i-len;
            if(y==-1||Z[N-1-y]==y+1) MA[len][ro.ha(l,r)].push_back(i);
        }
    }
    
    int Q;cin>>Q;
    while(Q--){
        string T;cin>>T;
        int M=si(T);
        for(int i=ro.n+1;i<=ro.n+M;i++){
            
            
            ro.h2[i]=ro.h2[i-1]*ro.base2+ll(T[i-1-ro.n]-'a');
            ro.h2[i]%=mod2;
            
            
            ro.ru2[i]=ro.ru2[i-1]*ro.base2%mod2;
        }
        for(int s=0;s<M;s++){
            int ans=0;
            for(int len=N;len<=N+s;len++){
                if(ro.ha(0,len)==ro.ha(N+s+1-len,N+s+1)) chmax(ans,len);
            }
            if(ans){
                cout<<ans<<" ";
                continue;
            }
            for(int p=1;p<=s;p++){
                if(ro.ha(0,p)==ro.ha(N+s+1-p,N+s+1)) chmax(ans,p);
            }
            for(int p=s+1;p<=s+1;p++){
                if(sav[p].count(ro.ha(N+s+1-p,N+s+1))) chmax(ans,sav[p][ro.ha(N+s+1-p,N+s+1)]);
                else{
                    int ma=0;
                    for(auto x:MA[p][ro.ha(N+s+1-p,N+s+1)]){
                        int y=x-p;
                        if(y==-1){
                            chmax(ans,p);
                            chmax(ma,p);
                        }else if(p==s+1&&Z[N-1-y]==y+1){
                            chmax(ans,p+Z[N-1-y]);
                            chmax(ma,p+Z[N-1-y]);
                        }
                    }
                    sav[p][ro.ha(N+s+1-p,N+s+1)]=ma;
                }
            }
            
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
    
    //for(int i=0;i<N;i++) cout<<Z[i]<<endl;
}