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
const int mod=1000000007,MAX=500005;
const int INF=1<<30;
//const ll INF=1LL<<60;

vector<int> l[MAX],r[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    string S;cin>>S;
    
    ll ans=0;
    
    vector<pair<ll,ll>> one;
    
    for(int k=0;k<=N+3;k++){
        l[k].push_back(-INF);
        r[k].push_back(-INF);
    }
    
    int i=0;
    while(i<N){
        while(i<N&&S[i]=='0') i++;
        if(i==N) break;
        int j=i;
        while(j<N&&S[j]=='1') j++;
        
        one.push_back(mp(i,j));
        
        for(int k=1;k<=j-i;k++){
            l[k].push_back(j-k);
            r[k].push_back(i+k);
        }
        
        i=j;
    }
    
    for(int k=0;k<=N+3;k++){
        l[k].push_back(INF);
        r[k].push_back(INF);
    }
    
    for(auto x:one){
        //cout<<x.fi<<" "<<x.se<<endl;
        ll len=x.se-x.fi;
        for(ll k=1;k<=len-2;k++){
            ans+=k*(len-1-k);
        }
        
        for(ll k=1;k<=len-1;k++){
            {
                auto it=lower_bound(all(l[k]),x.fi);
                it--;
                if(*it==-INF) ans+=k*(x.fi+1);
                else ans+=k*(x.fi-*it);
            }
            
            {
                auto it=lower_bound(all(r[k+1]),x.se+1);
                if(*it==INF) ans+=k*(N-x.se+1);
                else ans+=k*(*it-x.se);
            }
            
        }
        
        auto it=lower_bound(all(l[len]),x.fi);
        it--;
        
        auto it2=lower_bound(all(r[len+1]),x.se+1);
        
        ll su=1;
        
        if(*it==-INF) su*=(x.fi+1);
        else su*=(x.fi-*it);
        
        if(*it2==INF) su*=(N-x.se+1);
        else su*=(*it2-x.se);
        
        ans+=su*len;
    }
    
    cout<<ans<<endl;
    
}