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
const int mod=998244353,MAX=5005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll L,N;cin>>L>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    ll left=0,right=L+1;
    while(right-left>1){
        ll mid=(left+right)/2;
        ll now=0;
        bool f=true;
        for(int i=0;i<N;i++){
            if(now+mid<=A[i]) now=A[i];
            else if(i==N-1){
                if(now+mid>L) f=false;
            }else{
                if(now+mid>A[i+1]) f=false;
                else now+=mid;
            }
        }
        if(f) left=mid;
        else right=mid;
    }
    ll sm=left;
    left=sm-1;right=L;
    while(right-left>1){
        ll mid=(left+right)/2;
        ll lcan=0,rcan=0;
        bool f=true;
        for(int i=0;i<N;i++){
            ll l=lcan+sm,r=min(L,rcan+mid);
            if(r<A[i]){
                f=false;
                break;
            }
            if(l<=A[i]) l=A[i];
            
            if(i==N-1){
                if(l>L) f=false;
                if(r<L) f=false;
            }else{
                if(l>A[i+1]) f=false;
                chmin(r,A[i+1]);
            }
            if(l>r){
                f=false;
            }
            if(!f) break;
            
            lcan=l;
            rcan=r;
        }
        if(f) right=mid;
        else left=mid;
    }
    
    ll bi=right;
    
    ll mid=bi;
    vector<ll> dpl(N+1),dpr(N+1);
    ll lcan=0,rcan=0;
    for(int i=0;i<N;i++){
        ll l=lcan+sm,r=min(L,rcan+mid);
        
        if(l<=A[i]) l=A[i];
        
        if(i==N-1){
            //if(l>L) f=false;
            //if(r<L) f=false;
        }else{
            //if(l>A[i+1]) f=false;
            chmin(r,A[i+1]);
        }
        if(l>r){
            //f=false;
        }
        //if(!f) break;
        
        lcan=l;
        rcan=r;
        dpl[i+1]=lcan;
        dpr[i+1]=rcan;
    }
    
    vector<pair<ll,ll>> ans;
    ll now=L;
    
    for(int i=N-1;i>=0;i--){
        if(now-dpr[i]>=sm){
            ans.push_back(mp(dpr[i],now));
            now=dpr[i];
        }else{
            ans.push_back(mp(now-sm,now));
            now-=sm;
        }
    }
    
    reverse(all(ans));
    
    for(auto a:ans) cout<<a.fi<<" "<<a.se<<endl;
    //for(int i=0;i<=N;i++) cout<<dpl[i]<<" "<<dpr[i]<<endl;
}