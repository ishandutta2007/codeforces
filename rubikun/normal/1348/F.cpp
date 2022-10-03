#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=505;
const ll INF=1LL<<60;

struct dat{
    int l;
    int r;
    int id;
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<dat> S(N);
    for(int i=0;i<N;i++){
        cin>>S[i].l>>S[i].r;
        S[i].l--;
        S[i].r--;
        S[i].id=i;
    }
    sort(all(S),[](dat a,dat b){
        return make_pair(a.l,a.r)<make_pair(b.l,b.r);
    });
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
    
    int swa=-1,swb=-1;
    
    vector<int> ans(N);
    
    int now=0;
    pair<int,int> befo={-1,-1};
    
    for(int i=0;i<N;i++){
        while(now<N&&S[now].l==i){
            PQ.push({S[now].r,S[now].id});
            now++;
        }
        
        auto a=PQ.top();PQ.pop();
        ans[a.se]=i;
        if(a.se==befo.se){
            if(swa==-1){
                swa=befo.fi;
                swb=befo.se;
            }
        }
        
        if(si(PQ)){
            auto b=PQ.top();
            
            if(a.fi==b.fi){
                if(swa==-1){
                    swa=a.se;
                    swb=b.se;
                }
            }
            
            ans[a.se]=i;
            if(a.fi!=i){
                befo.fi=a.se;
                befo.se=b.se;
            }else{
                befo.fi=-1;
                befo.se=-1;
            }
            
        }else befo={-1,-1};
    }
    
    if(swa==-1){
        cout<<"YES\n";
        for(int i=0;i<N;i++){
            cout<<ans[i]+1<<" ";
        }
        cout<<endl;
    }else{
        cout<<"NO\n";
        for(int i=0;i<N;i++){
            cout<<ans[i]+1<<" ";
        }
        cout<<endl;
        swap(ans[swa],ans[swb]);
        for(int i=0;i<N;i++){
            cout<<ans[i]+1<<" ";
        }
        cout<<endl;
    }
}