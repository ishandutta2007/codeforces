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
    
    int N,M;cin>>N>>M;
    vector<set<int>> SE(N);
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        SE[a].insert(b);
        SE[b].insert(a);
    }
    vector<int> win(N);
    int ans=0;
    for(int i=0;i<N;i++){
        if(si(SE[i])==0||*(SE[i].rbegin())<i){
            ans++;
            win[i]=true;
        }
    }
    
    int Q;cin>>Q;
    while(Q--){
        int t;cin>>t;
        if(t==1){
            int a,b;cin>>a>>b;a--;b--;
            SE[a].insert(b);
            SE[b].insert(a);
            if(si(SE[a])&&*(SE[a].rbegin())>=a){
                if(win[a]){
                    ans--;
                    win[a]=false;
                }
            }
            if(si(SE[b])&&*(SE[b].rbegin())>=b){
                if(win[b]){
                    ans--;
                    win[b]=false;
                }
            }
        }
        if(t==2){
            int a,b;cin>>a>>b;a--;b--;
            SE[a].erase(b);
            SE[b].erase(a);
            if(si(SE[a])==0||*(SE[a].rbegin())<a){
                if(!win[a]){
                    ans++;
                    win[a]=true;
                }
            }
            if(si(SE[b])==0||*(SE[b].rbegin())<b){
                if(!win[b]){
                    ans++;
                    win[b]=true;
                }
            }
        }
        if(t==3){
            cout<<ans<<"\n";
        }
    }
}