#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1000003;
const ll INF=1LL<<60;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M,K;
    ll A,B;cin>>N>>M>>A>>B>>K;
    vector<ll> X(N),Y(M);
    for(int i=0;i<N;i++){
        //cin>>X[i];
        scanf("%lld",&X[i]);
    }
    for(int i=0;i<M;i++){
        //cin>>Y[i];
        scanf("%lld",&Y[i]);
    }
    
    bool can=true;
    
    ll maxi=-1;
    
    if(K>=N||K>=M){
        cout<<-1<<"\n";
        return 0;
    }
    
    for(int i=0;i<=K;i++){
        ll arrive=X[i]+A;
        int which=lower_bound(all(Y),arrive)-Y.begin();
        if(which+K-i>=M) can=false;
        else maxi=max(maxi,Y[which+K-i]+B);
        
        //cout<<which+K-i<<endl;
    }
    
    if(can){
        cout<<maxi<<endl;
    }else cout<<-1<<endl;
}