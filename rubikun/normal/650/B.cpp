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
    
    ll N,A,B,T;cin>>N>>A>>B>>T;
    string S;cin>>S;
    vector<ll> l(N),r(N);
    if(S[0]=='h') l[0]=1;
    else l[0]=1+B;
    
    for(int i=1;i<N;i++){
        if(S[N-i]=='h') l[i]=1;
        else l[i]=1+B;
        l[i]+=l[i-1]+A;
        
        if(S[i]=='h') r[i]=1;
        else r[i]=1+B;
        r[i]+=r[i-1]+A;
    }
    
    int ans=0;
    
    if(l[0]>T){
        cout<<0<<endl;
        return 0;
    }
    
    int can=N-1;
    
    for(int i=0;i<N;i++){
        if(l[i]>T) break;
        chmax(ans,i+1);
        
        ll need=l[i]+A*i;
        if(need>T) break;
        
        while(can>=0&&need+r[can]>T) can--;
        
        chmax(ans,i+1+can);
    }
    
    can=N-1;
    
    for(int i=0;i<N;i++){
        if(l[0]+r[i]>T) break;
        chmax(ans,i+1);
        
        ll need=l[0]+r[i]+A*i;
        if(need>T) break;
        
        while(can>=0&&need+l[can]-l[0]>T) can--;
        
        chmax(ans,i+1+can);
    }
    
    chmin(ans,int(N));
    
    cout<<ans<<endl;
}