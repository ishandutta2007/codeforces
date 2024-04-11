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
const int mod=1000000007,MAX=100005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll H,W,N;cin>>W>>H>>N;
    set<ll> SH,SW;
    SH.insert(0);
    SH.insert(H);
    SW.insert(0);
    SW.insert(W);
    multiset<ll> lenH,lenW;
    lenH.insert(H);
    lenW.insert(W);
    
    while(N--){
        char c;ll x;cin>>c>>x;
        if(c=='H'){
            auto it=SH.lower_bound(x);it--;
            ll a=*it;it++;
            ll b=*it;
            lenH.erase(lenH.lower_bound(b-a));
            lenH.insert(x-a);
            lenH.insert(b-x);
            SH.insert(x);
        }else{
            auto it=SW.lower_bound(x);it--;
            ll a=*it;it++;
            ll b=*it;
            lenW.erase(lenW.lower_bound(b-a));
            lenW.insert(x-a);
            lenW.insert(b-x);
            SW.insert(x);
        }
        
        cout<<(*lenH.rbegin())*(*lenW.rbegin())<<"\n";
    }
}