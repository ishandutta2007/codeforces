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
const int mod=1000000007,MAX=2005;
const ll INF=1LL<<60;

vector<pair<ll,ll>> P;

bool compare(pair<int,int> i,pair<int,int> j){
    pair<ll,ll> a=mp(P[i.se].fi-P[i.fi].fi,P[i.se].se-P[i.fi].se);
    pair<ll,ll> b=mp(P[j.se].fi-P[j.fi].fi,P[j.se].se-P[j.fi].se);
    int at,bt;
    if(a.se>0||(a.se==0&&a.fi>0)) at=0;
    else at=1;
    
    if(b.se>0||(b.se==0&&b.fi>0)) bt=0;
    else bt=1;
    
    if(at!=bt) return at<bt;
    return a.fi*b.se-a.se*b.fi>0;
}

// [0,2pi)

ll f(int i,int j,int k){
    pair<ll,ll> a=mp(P[j].fi-P[i].fi,P[j].se-P[i].se);
    pair<ll,ll> b=mp(P[k].fi-P[i].fi,P[k].se-P[i].se);
    return (a.fi*b.se-a.se*b.fi);
}

void output(int i){
    cout<<P[i].fi<<" "<<P[i].se<<endl;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    ll S;cin>>S;
    S*=2;
    
    P.resize(N);
    for(int i=0;i<N;i++){
        cin>>P[i].fi>>P[i].se;
    }
    sort(all(P),[](auto a,auto b){
        if(a.se==b.se) return a.fi<b.fi;
        return a.se<b.se;
    });
    
    vector<pair<int,int>> id;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            id.push_back(mp(i,j));
        }
    }
    
    sort(all(id),compare);
    
    vector<int> A(N),pos(N);
    iota(all(A),0);
    iota(all(pos),0);
    
    for(auto x:id){
        int i=x.fi,j=x.se;
        //cout<<A[i]<<" "<<A[j]<<endl;
        swap(A[i],A[j]);
        swap(pos[A[i]],pos[A[j]]);
        
        int left=A[i],right=N;
        while(right-left>1){
            int mid=(left+right)/2;
            ll T=f(i,j,pos[mid]);
            if(T<=S) left=mid;
            else right=mid;
        }
        
        if(left<N&&f(i,j,pos[left])==S){
            cout<<"Yes"<<endl;
            output(i);
            output(j);
            output(pos[left]);
            return 0;
        }
    }
    
    cout<<"No"<<endl;
}