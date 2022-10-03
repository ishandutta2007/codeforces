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

//#define ld long double

typedef pair<ll,ll> pii;
deque<pair<pii,vector<int>>> dq;

bool check(pii a,pii b,pii c){
    //return (1/c.second-1/b.second)*(1/b.first-1/a.first)>(1/b.second-1/a.second)*(1/c.first-1/b.first);
    return (a.se*b.se-a.se*c.se)*(a.fi*c.fi-b.fi*c.fi)>(a.se*c.se-b.se*c.se)*(a.fi*b.fi-a.fi*c.fi);
}

void add(ll a,ll b,int id){
    pii p=make_pair(a,b);
    while(dq.size()>=2&&check(dq[dq.size()-2].fi,dq[dq.size()-1].fi,p)) dq.pop_back();
    dq.push_back(mp(p,vector<int>{id}));
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<pair<pii,int>> S(N);
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        S[i].fi.fi=b;
        S[i].fi.se=a;
        S[i].se=i;
    }
    sort(all(S),[](auto a,auto b){
        if(a.fi.fi==b.fi.fi){
            return a.fi.se>b.fi.se;
        }else{
            return a.fi.fi<b.fi.fi;
        }
    });
    
    for(auto a:S){
        /*
        cout<<a.fi.fi<<" "<<a.fi.se<<" "<<a.se<<endl;
        for(auto a:dq) cout<<a.se<<endl;
        if(si(dq)) cout<<dq.back().fi.fi<<" "<<dq.back().fi.se<<endl;
        cout<<endl;
         */
        if(si(dq)&&dq.back().fi==a.fi){
            dq.back().se.push_back(a.se);
            continue;
        }
        if(si(dq)&&dq.back().fi.fi==a.fi.fi) continue;
        
        while(si(dq)&&dq.back().fi.se<=a.fi.se) dq.pop_back();
        //if(si(dq)&&dq.back().fi.se==a.fi.se) continue;
        
        add(a.fi.fi,a.fi.se,a.se);
        /*
        if(si(dq)&&dq.back().fi==a.fi){
            dq.push_back(a);
        }else{
            if(si(dq)&&dq.back().fi.fi==a.fi.fi) continue;
        }
         */
    }
    
    set<int> SE;
    for(auto a:dq){
        for(int b:a.se){
            SE.insert(b+1);
        }
    }
    
    for(int a:SE) cout<<a<<" ";
    cout<<endl;
}