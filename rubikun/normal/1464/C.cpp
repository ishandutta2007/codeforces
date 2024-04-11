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

ll rui[40];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;ll T;cin>>N>>T;
    string S;cin>>S;
    rui[0]=1;
    for(int i=1;i<30;i++) rui[i]=rui[i-1]*2;
    
    T-=rui[int(S.back()-'a')];
    S.pop_back();
    
    T+=rui[int(S.back()-'a')];
    S.pop_back();
    
    N-=2;
    
    //cout<<N<<" "<<S<<" "<<T<<endl;
    
    vector<ll> cnt(26);
    for(int i=0;i<N;i++){
        cnt[int(S[i]-'a')]++;
        T+=rui[int(S[i]-'a')];
    }
    
    //cout<<N<<" "<<S<<" "<<T<<endl;
    
    //for(int i=0;i<26;i++) cout<<cnt[i]<<" ";
    //cout<<endl;
    
    if(T<0){
        cout<<"No"<<endl;
        return 0;
    }
    
    for(int i=25;i>=0;i--){
        ll can=min(cnt[i],T/rui[i+1]);
        T-=rui[i+1]*can;
    }
    
    //cout<<T<<endl;
    
    if(T==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}