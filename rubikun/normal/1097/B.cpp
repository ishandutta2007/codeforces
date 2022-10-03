#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<59;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    bool ok=false;
    
    for(int bit=0;bit<(1<<N);bit++){
        int sum=0;
        for(int i=0;i<N;i++){
            if(bit&(1<<i)){
                sum+=A[i];
            }else{
                sum+=360-A[i];
            }
        }
        if(sum%360==0) ok=true;
    }
    
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}