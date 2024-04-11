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

struct BIT{
    vector<int> bit;
    int N;
    //1-indexed
    
    void init(int n_){
        N=n_;
        n_*=2;
        for(int i=30;i>=0;i--){
            if(n_&(1<<i)){
                n_=1<<i;
                n_++;
                break;
            }
        }
        bit.assign(n_,0);
    }
    
    int sum(int i){
        int s=0;
        while(i>0){
            s+=bit[i];
            i-=i&-i;
        }
        return s;
    }
    
    //st=sum(t)-sum(s-1)
    
    void add(int i,int x){
        while(i<=N){
            bit[i]+=x;
            i+=i&-i;
        }
    }
};

int f(char c){
    if(c=='A') return 0;
    if(c=='T') return 1;
    if(c=='G') return 2;
    if(c=='C') return 3;
    
    return -1;
}

BIT bi[10][10][4];

void add(int p,char c,int diff){
    int k=f(c);
    
    for(int i=0;i<10;i++){
        int j=p%(i+1);
        bi[i][j][k].add(p+1,diff);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    int N=si(S);
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<4;k++){
                bi[i][j][k].init(N);
            }
        }
    }
    
    for(int p=0;p<N;p++){
        add(p,S[p],1);
    }
    
    int Q;cin>>Q;
    while(Q--){
        int q;cin>>q;
        if(q==1){
            int p;char c;cin>>p>>c;
            p--;
            add(p,S[p],-1);
            S[p]=c;
            add(p,S[p],1);
        }else{
            int l,r;cin>>l>>r;
            l--;r--;
            string T;cin>>T;
            
            int M=si(T);
            
            ll ans=0;
            
            for(int i=0;i<M;i++){
                int j=(i+l)%M;
                ans+=bi[M-1][j][f(T[i])].sum(r+1);
                ans-=bi[M-1][j][f(T[i])].sum(l);
            }
            
            cout<<ans<<"\n";
        }
    }
}