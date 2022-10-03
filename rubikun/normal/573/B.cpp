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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N+2);
    for(int i=0;i<N;i++){
        cin>>A[i+1];
    }
    
    ll left=0,right=INF;
    
    while(right-left>1){
        ll mid=(left+right)/2;
        
        vector<int> imo(N+10);
        
        for(int i=0;i<N+2;i++){
            ll l=i-(mid-1-A[i]),r=i+(mid-1-A[i]);
            if(l>r) continue;
            chmax(l,0LL);
            chmin(r,ll(N+4));
            
            imo[l]++;
            imo[r+1]--;
        }
        
        for(int i=1;i<=N+5;i++) imo[i]+=imo[i-1];
        
        bool ok=false;
        for(int i=1;i<=N;i++) if(imo[i]==0) ok=true;
        
        if(ok) left=mid;
        else right=mid;
    }
    
    cout<<left<<endl;
}