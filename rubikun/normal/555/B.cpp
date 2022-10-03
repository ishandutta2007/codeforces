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
//const int INF=1<<30;
const ll INF=1LL<<60;

struct dat{
    ll l;
    ll r;
    int id;
    int ans;
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    
    vector<ll> l(N),r(N);
    for(int i=0;i<N;i++) cin>>l[i]>>r[i];
    
    vector<dat> S(N-1);
    for(int i=0;i<N-1;i++){
        S[i].l=l[i+1]-r[i];
        S[i].r=r[i+1]-l[i];
        S[i].id=i;
        S[i].ans=-1;
    }
    
    sort(all(S),[](auto a,auto b){
        return a.r<b.r;
    });
    
    set<pair<ll,int>> SE;
    for(int i=0;i<M;i++){
        ll x;cin>>x;
        SE.insert(mp(x,i));
    }
    
    SE.insert(mp(-INF,-1));
    SE.insert(mp(INF,-1));
    
    for(int i=0;i<N-1;i++){
        //cout<<S[i].l<<" "<<S[i].r<<" "<<S[i].id<<endl;
        auto it=SE.lower_bound(mp(S[i].l,-2));
        if((*it).fi>S[i].r){
            cout<<"No"<<endl;
            return 0;
        }
        S[i].ans=(*it).se;
        SE.erase(it);
    }
    
    cout<<"Yes"<<endl;
    
    sort(all(S),[](auto a,auto b){
        return a.id<b.id;
    });
    
    for(int i=0;i<N-1;i++){
        cout<<S[i].ans+1<<" ";
    }
    cout<<endl;
}