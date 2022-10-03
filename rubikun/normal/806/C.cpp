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
    
    vector<ll> p={1};
    while(p.back()<1e12){
        p.push_back(p.back()*2);
    }
    
    int N;cin>>N;
    vector<ll> A(N),B,cnt(50);
    for(int i=0;i<N;i++) cin>>A[i];
    
    for(int i=0;i<N;i++){
        bool out=false;
        for(int j=0;j<si(p);j++){
            if(A[i]==p[j]){
                cnt[j]++;
                out=true;
            }
        }
        if(!out) B.push_back(A[i]);
    }
    
    int left=(cnt[0]+1)/2-1,right=cnt[0]+1;
    
    while(right-left>1){
        int mid=(left+right)/2;
        vector<ll> save=cnt;
        
        vector<vector<ll>> C(mid,vector<ll>(1,1));
        cnt[0]-=mid;
        for(int j=1;j<45;j++){
            for(int i=0;i<mid;i++){
                if(cnt[j]==0) break;
                if(C[i].back()==p[j]/2){
                    C[i].push_back(p[j]);
                    cnt[j]--;
                }
            }
        }
        
        priority_queue<ll> PQ;
        for(ll a:B) PQ.push(a);
        for(int j=0;j<45;j++){
            while(cnt[j]){
                PQ.push(p[j]);
                cnt[j]--;
            }
        }
        bool ok=true;
        for(int i=0;i<mid;i++){
            if(PQ.empty()) break;
            ll a=PQ.top();
            if(C[i].back()*2>=a){
                PQ.pop();
            }else{
                ok=false;
                break;
            }
        }
        
        if(!PQ.empty()) ok=false;
        
        if(ok) right=mid;
        else left=mid;
        
        cnt=save;
    }
    
    if(right<=cnt[0]){
        for(int i=right;i<=cnt[0];i++) cout<<i<<" ";
        cout<<"\n";
    }else{
        cout<<-1<<"\n";
    }
}