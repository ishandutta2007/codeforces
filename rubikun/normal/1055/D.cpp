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
const int mod1=1000000007,mod2=1000000009,MAX=5005,INF=1<<30;

ll ru1[MAX],ru2[MAX];

struct Rollinghash{
    string S;
    int n;
    int base1;
    int base2;
    vector<ll> h1,h2;
    
    void make(string &T,int ba1,int ba2){
        S=T;
        n=S.size();
        h1.assign(n+1,0);
        h2.assign(n+1,0);
        base1=ba1;
        base2=ba2;
        
        //ru1[0]=1;
        //ru2[0]=1;
        
        for(int i=1;i<=n;i++){
            h1[i]=h1[i-1]*base1+ll(S[i-1]-'A');
            h1[i]%=mod1;
            
            h2[i]=h2[i-1]*base2+ll(S[i-1]-'A');
            h2[i]%=mod2;
            
            //ru1[i]=ru1[i-1]*base1%mod1;
            //ru2[i]=ru2[i-1]*base2%mod2;
        }
    }
    
    pair<ll,ll> ha(int l,int r){
        pair<ll,ll> res;
        res.fi=(h1[r]-h1[l]*ru1[r-l]%mod1+mod1)%mod1;
        res.se=(h2[r]-h2[l]*ru2[r-l]%mod2+mod2)%mod2;
        
        return res;
    }//
};

const int ha1=37,ha2=43;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ru1[0]=1;
    ru2[0]=1;
    for(int i=1;i<MAX;i++){
        ru1[i]=ru1[i-1]*ha1%mod1;
        ru2[i]=ru2[i-1]*ha2%mod2;
    }
    
    int N;cin>>N;
    vector<string> S(N),T(N);
    for(int i=0;i<N;i++) cin>>S[i];
    for(int i=0;i<N;i++) cin>>T[i];
    
    vector<int> wh(N),need;
    
    pair<string,string> SE=mp("","");
    
    vector<string> A,B;
    
    for(int i=0;i<N;i++){
        if(S[i]==T[i]) continue;
        need.push_back(i);
        wh[i]=1;
        
        int s=0,t=si(S[i])-1;
        while(1){
            if(S[i][s]!=T[i][s]) break;
            s++;
        }
        
        while(1){
            if(S[i][t]!=T[i][t]) break;
            t--;
        }
        
        if(si(SE.fi)==0){
            SE=mp(S[i].substr(s,t-s+1),T[i].substr(s,t-s+1));
        }else{
            if(SE!=mp(S[i].substr(s,t-s+1),T[i].substr(s,t-s+1))){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        
        string x=S[i].substr(0,s),y=S[i].substr(t+1);
        reverse(all(x));
        A.push_back(x);
        B.push_back(y);
    }
    
    string from=SE.fi,to=SE.se;
    
    //cout<<from<<" "<<to<<endl;
    
    string X,Y,xx=A[0],yy=B[0];
    
    
    for(int i=1;i<si(A);i++){
        for(int j=0;j<min(si(A[i]),si(xx));j++){
            if(A[i][j]!=xx[j]){
                while(si(xx)!=j) xx.pop_back();
                break;
            }
        }
        while(si(xx)>si(A[i])) xx.pop_back();
    }
    X=xx;
    reverse(all(X));
    
    for(int i=1;i<si(B);i++){
        for(int j=0;j<min(si(B[i]),si(yy));j++){
            if(B[i][j]!=yy[j]){
                while(si(yy)!=j) yy.pop_back();
                break;
            }
        }
        while(si(yy)>si(B[i])) yy.pop_back();
    }
    Y=yy;
    
    string ans1=X+from+Y,ans2=X+to+Y;
    
    //for(auto a:A) cout<<a<<endl;
    //for(auto b:B) cout<<b<<endl;
    
    Rollinghash base;
    base.make(ans1,ha1,ha2);
    
    for(int i=0;i<N;i++){
        if(wh[i]) continue;
        
        Rollinghash rol;
        rol.make(S[i],ha1,ha2);
        
        for(int j=0;j+si(ans1)<=si(S[i]);j++){
            auto x=rol.ha(j,j+si(ans1)),y=base.ha(0,si(ans1));
            if(x==y){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    
    for(int i=0;i<si(need);i++){
        Rollinghash rol;
        rol.make(S[need[i]],ha1,ha2);
        
        int mi=INF;
        
        for(int j=0;j+si(ans1)<=si(S[need[i]]);j++){
            auto x=rol.ha(j,j+si(ans1)),y=base.ha(0,si(ans1));
            if(x==y){
                chmin(mi,j);
                break;
            }
        }
        
        if(mi!=si(A[i])-si(X)){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    
    cout<<"YES"<<endl;
    cout<<ans1<<endl;
    cout<<ans2<<endl;
}