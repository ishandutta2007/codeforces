#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1000003;
const ll INF=1LL<<60;

int main(){
    
    vector<int> A={1,6,28,120,496,2016,8128,32640,130816};
    int N;cin>>N;
    int ans=0;
    for(int p:A){
        if(N%p==0) ans=p;
    }
    
    cout<<ans<<endl;
    
}