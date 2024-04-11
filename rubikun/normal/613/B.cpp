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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,A,X,Y;cin>>N>>A>>X>>Y;
    ll lim;cin>>lim;
    vector<pair<ll,int>> S(N);
    for(int i=0;i<N;i++){
        cin>>S[i].fi;
        S[i].se=i;
    }
    sort(all(S));
    //reverse(all(S));
    vector<ll> rui(N+1);
    for(int i=1;i<=N;i++) rui[i]=rui[i-1]+S[i-1].fi;
    
    pair<ll,int> ans=mp(-1,-1);
    ll need=0;
    for(int i=0;i<=N;i++){
        if(i) need+=(A-S[N-i].fi);
        if(need<=lim){
            ll left=0,right=A+1;
            while(right-left>1){
                ll mid=(left+right)/2;
                auto it=lower_bound(all(S),mp(mid,-1));
                ll d=it-S.begin();
                chmin(d,N-i);
                if(need+mid*d-rui[d]<=lim) left=mid;
                else right=mid;
            }
            chmax(ans,mp(X*i+Y*left,i));
        }
    }
    
    cout<<ans.fi<<endl;
    
    if(Y==0){
        for(int i=N-1;i>=N-ans.se;i--) S[i].fi=A;
        sort(all(S),[](auto a,auto b){
            return a.se<b.se;
        });
        for(int i=0;i<N;i++) cout<<S[i].fi<<" ";
        cout<<"\n";
    }else{
        ll aim=(ans.fi-X*ans.se)/Y;
        for(int i=0;i<N;i++){
            if(S[i].fi<aim) S[i].fi=aim;
        }
        for(int i=N-1;i>=N-ans.se;i--) S[i].fi=A;
        sort(all(S),[](auto a,auto b){
            return a.se<b.se;
        });
        for(int i=0;i<N;i++) cout<<S[i].fi<<" ";
        cout<<"\n";
    }
}