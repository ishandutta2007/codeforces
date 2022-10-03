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
const int mod=1000000007,MAX=300005,INF=1<<30;
set<int> SE[MAX];
set<pair<int,int>> now;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,Q;cin>>N>>Q;
    now.insert(mp(INF,-1));
    int id=0;
    for(int i=0;i<Q;i++){
        int t,k;cin>>t>>k;
        if(t==1){
            k--;
            SE[k].insert(id);
            now.insert(mp(id,k));
            id++;
        }
        if(t==2){
            k--;
            for(auto a:SE[k]){
                now.erase(mp(a,k));
            }
            SE[k].clear();
        }
        if(t==3){
            auto it=now.begin();
            while(1){
                if((*it).fi>=k) break;
                SE[(*it).se].erase((*it).fi);
                it=now.erase(it);
            }
        }
        
        cout<<si(now)-1<<"\n";
    }
}