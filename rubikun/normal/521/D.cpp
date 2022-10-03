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

#define ld long double

vector<pair<ll,int>> ad[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,K;cin>>K>>N>>M;
    vector<ll> A(K);
    for(int i=0;i<K;i++) cin>>A[i];
    vector<pair<ll,int>> MA(K);
    for(int i=0;i<K;i++) MA[i]=mp(A[i],INF);
    
    vector<pair<ld,pair<int,int>>> cand;
    
    for(int i=0;i<N;i++){
        ll t,x,y;cin>>t>>x>>y;x--;
        if(t==1){
            chmax(MA[x],mp(y,i));
        }
        if(t==2){
            ad[x].push_back(mp(y,i));
        }
        if(t==3){
            cand.push_back(mp(y,mp(-1,i)));
        }
    }
    
    for(int i=0;i<K;i++){
        sort(all(ad[i]));
        reverse(all(ad[i]));
        
        vector<pair<ll,int>> ma(si(ad[i])+2);
        ma[0]=mp(A[i],0);
        for(int j=1;j<=si(ad[i]);j++){
            ma[j].fi=ma[j-1].fi+ad[i][j-1].fi;
            ma[j].se=0;
        }
        if(MA[i].se!=INF){
            chmax(ma[1],mp(MA[i].fi,1));
            ll now=MA[i].fi;
            for(int j=2;j<=si(ad[i])+1;j++){
                chmax(ma[j],mp(now+ad[i][j-2].fi,1));
                now+=ad[i][j-2].fi;
            }
        }
        
        for(int j=1;j<=si(ad[i])+1;j++){
            if(ma[j].fi==0) break;
            cand.push_back(mp((ld)(ma[j].fi)/ma[j-1].fi,mp(i,ma[j].se)));
        }
    }
    
    sort(all(cand));
    reverse(all(cand));
    
    //for(auto a:cand) cout<<a.fi<<" "<<a.se.fi<<" "<<a.se.se<<endl;
    
    vector<int> kake;
    
    vector<int> upd(K),cn(K);
    
    for(int i=0;i<min(si(cand),M);i++){
        if(cand[i].se.fi==-1){
            kake.push_back(cand[i].se.se);
        }else{
            if(cand[i].se.se) upd[cand[i].se.fi]=true;
            cn[cand[i].se.fi]++;
        }
    }
    
    vector<int> ans;
    
    for(int i=0;i<K;i++){
        if(upd[i]){
            ans.push_back(MA[i].se);
            cn[i]--;
        }
    }
    
    for(int i=0;i<K;i++){
        for(int j=0;j<cn[i];j++){
            ans.push_back(ad[i][j].se);
        }
    }
    
    for(int a:kake) ans.push_back(a);
    
    cout<<si(ans)<<endl;
    for(int a:ans) cout<<a+1<<" ";
    cout<<endl;
}