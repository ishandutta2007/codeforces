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
    if(c=='R') return 0;
    if(c=='P') return 1;
    if(c=='S') return 2;
    return -1;
}

BIT bi[3];
set<int> SE[3];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,Q;cin>>N>>Q;
    string S;cin>>S;
    
    for(int i=0;i<3;i++) bi[i].init(N);
    
    for(int i=0;i<N;i++){
        bi[f(S[i])].add(i+1,1);
        SE[f(S[i])].insert(i);
    }
    Q++;
    
    while(Q--){
        int res=0;
        for(int t=0;t<3;t++){
            int a=N,b=-1,c=N,d=-1;
            if(si(SE[(t+1)%3])){
                a=*SE[(t+1)%3].begin();
                b=*SE[(t+1)%3].rbegin();
            }
            if(si(SE[(t+2)%3])){
                c=*SE[(t+2)%3].begin();
                d=*SE[(t+2)%3].rbegin();
            }
            
            res+=bi[t].sum(N);
            
            if(a<c&&a!=N) res-=(bi[t].sum(min(N,c+1))-bi[t].sum(min(N,a+1)));
            if(d<b&&b!=-1) res-=(bi[t].sum(b+1)-bi[t].sum(d+1));
            if(c==N&&a!=N) res+=bi[t].sum(b+1)-bi[t].sum(a+1);
        }
        cout<<res<<"\n";
        
        if(Q==0) continue;
        
        int a;char b;cin>>a>>b;
        a--;
        
        bi[f(S[a])].add(a+1,-1);
        SE[f(S[a])].erase(a);
        
        S[a]=b;
        
        bi[f(S[a])].add(a+1,1);
        SE[f(S[a])].insert(a);
    }
    
}