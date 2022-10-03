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
const int mod=1000000007,MAX=705,INF=1<<30;

bool compare(pair<ll,ll> a,pair<ll,ll> b){
    int at,bt;
    if(a.se>0||(a.se==0&&a.fi>0)) at=0;
    else at=1;
    
    if(b.se>0||(b.se==0&&b.fi>0)) bt=0;
    else bt=1;
    
    if(at!=bt) return at<bt;
    return a.fi*b.se-a.se*b.fi>0;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<pair<ll,ll>> P(N);
    for(int i=0;i<N;i++) cin>>P[i].fi>>P[i].se;
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        vector<pair<ll,ll>> A;
        for(int j=0;j<N;j++){
            if(i==j) continue;
            A.push_back(mp(P[j].fi-P[i].fi,P[j].se-P[i].se));
        }
        sort(all(A),compare);
        for(int j=0;j<N-1;j++) A.push_back(A[j]);
        
        for(int j=0;j<N-1;j++){
            int left=j,right=j+N-1;
            while(right-left>1){
                int mid=(left+right)/2;
                if(A[j].fi*A[mid].se-A[j].se*A[mid].fi>0) left=mid;
                else right=mid;
            }
            
            ll l=left-j,r=j+N-1-right;
            
            ans+=l*(l-1)/2*r*(r-1)/2;
        }
    }
    
    cout<<ans/2<<endl;
}