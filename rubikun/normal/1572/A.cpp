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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<vector<int>> G(N);
        vector<int> need(N);
        set<int> can;
        int sum=0;
        for(int i=0;i<N;i++){
            int x;cin>>x;
            for(int j=0;j<x;j++){
                int a;cin>>a;
                a--;
                G[a].push_back(i);
            }
            need[i]=x;
            if(x==0) can.insert(i);
        }
        
        if(si(can)==0){
            cout<<-1<<"\n";
            continue;
        }
        
        int ans=0;
        while(1){
            ans++;
            set<int> nex;
            auto it=can.begin();
            while(it!=can.end()){
                int a=*it;
                sum++;
                for(int to:G[a]){
                    need[to]--;
                    if(need[to]==0){
                        if(to>a){
                            can.insert(to);
                        }else{
                            nex.insert(to);
                        }
                    }
                }
                it=can.lower_bound(a);
                it=can.erase(it);
            }
            if(sum==N) break;
            if(si(nex)==0) break;
            can=nex;
        }
        
        for(int i=0;i<N;i++) if(need[i]>0) ans=-1;
        
        cout<<ans<<"\n";
    }
}