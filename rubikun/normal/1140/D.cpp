#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000003,MAX=200001,INF=1<<30;

bool compare(pair<ll,ll> a,pair<ll,ll> b){
    if(a.second==b.second) return a.first>b.first;
    return a.second>b.second;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    ll sum=0;
    for(ll i=2;i<=N-1;i++){
        sum+=i*(i+1);
    }
    cout<<sum<<endl;
}