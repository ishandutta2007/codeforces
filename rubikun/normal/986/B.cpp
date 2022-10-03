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
const int mod=1000000007,MAX=100005,INF=1<<30;

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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    
    vector<int> A(N),pos(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        A[i]--;
        pos[A[i]]=i;
    }
    
    BIT bi;
    bi.init(N+1);
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        ans+=i-bi.sum(pos[i]);
        bi.add(pos[i]+1,1);
    }
    
    ans%=2;
    N%=2;
    
    if(ans==N) cout<<"Petr\n";
    else cout<<"Um_nik\n";
}