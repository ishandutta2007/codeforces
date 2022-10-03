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
//const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> t(N),p(N);
    for(int i=0;i<N;i++){
        string s;cin>>s;
        if(s=="ADD") t[i]=0;
        else t[i]=1;
        
        cin>>p[i];
    }
    
    map<pair<int,int>,ll> MA;
    MA[mp(-INF,INF)]=1;
    
    set<int> SE;
    
    SE.insert(-INF);
    SE.insert(INF);
    
    int i=0;
    while(1){
        int j=i;
        while(j<N&&t[j]==0) j++;
        if(j==N){
            ll ans=0;
            for(auto x:MA){
                int cnt=0;
                for(int k=i;k<j;k++){
                    if(x.fi.fi<p[k]&&p[k]<x.fi.se) cnt++;
                }
                //cout<<x.fi.fi<<" "<<x.fi.se<<" "<<cnt<<endl;
                ans+=x.se*(cnt+1);
                ans%=mod;
            }
            
            cout<<ans<<endl;
            return 0;
        }
        
        for(int k=i;k<j;k++) SE.insert(p[k]);
        SE.erase(p[j]);
        
        map<pair<int,int>,ll> to;
        
        for(auto x:MA){
            if(p[j]<x.fi.fi||x.fi.se<p[j]) continue;
            
            if(x.fi.fi==p[j]||x.fi.se==p[j]){
                auto it=SE.lower_bound(p[j]),it2=SE.lower_bound(p[j]);
                it--;
                to[mp(*it,*it2)]+=x.se;
                to[mp(*it,*it2)]%=mod;
            }else{
                bool ok=false;
                for(int k=i;k<j;k++) if(p[k]==p[j]) ok=true;
                if(!ok) continue;
                
                auto it=SE.lower_bound(p[j]),it2=SE.lower_bound(p[j]);
                it--;
                to[mp(*it,*it2)]+=x.se*2;
                to[mp(*it,*it2)]%=mod;
            }
        }
        
        MA=to;
        i=j+1;
    }
    
    ll ans=0;
    
    for(auto x:MA){
        ans+=x.se;
        ans%=mod;
    }
    
    cout<<ans<<endl;
}