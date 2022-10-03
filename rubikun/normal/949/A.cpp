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
    
    string S;cin>>S;
    int cnt0=0,cnt1=0;
    int N=si(S);
    
    for(int i=0;i<N;i++){
        if(S[i]=='0') cnt0++;
        else cnt1++;
    }
    
    int ans=cnt0-cnt1;
    if(ans<=0){
        cout<<-1<<endl;
        return 0;
    }
    
    vector<vector<int>> wh(ans,vector<int>());
    set<int> SE0,SE1;
    for(int i=0;i<ans;i++){
        SE0.insert(i);
    }
    
    bool ok=true;
    
    for(int i=0;i<N;i++){
        if(S[i]=='0'){
            if(!si(SE0)){
                ok=false;
                break;
            }
            int a=*(SE0.begin());
            wh[a].push_back(i+1);
            SE0.erase(a);
            SE1.insert(a);
        }else{
            if(!si(SE1)){
                ok=false;
                break;
            }
            int a=*(SE1.begin());
            wh[a].push_back(i+1);
            SE1.erase(a);
            SE0.insert(a);
        }
    }
    
    if(ok){
        cout<<ans<<endl;
        for(int i=0;i<ans;i++){
            cout<<si(wh[i])<<" ";
            for(int a:wh[i]) cout<<a<<" ";
            cout<<"\n";
        }
    }else{
        cout<<-1<<endl;
    }
}