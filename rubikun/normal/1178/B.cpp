#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    string S;cin>>S;
    S+='o';
    ll ans=0;
    int cnt=0;
    vector<int> A={0};
    for(int i=0;i<int(S.size());i++){
        if(S[i]=='v') cnt++;
        else{
            A.push_back(max(cnt-1,0));
            cnt=0;
        }
    }
    vector<int> sum(A.size(),0);
    
    for(int i=1;i<A.size();i++){
        sum[i]=sum[i-1]+A[i];
    }
    
    for(int i=1;i<A.size()-1;i++){
        ans+=ll(max(0,sum[i]))*ll(max(0,sum[A.size()-1]-sum[i]));
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    
}