#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2001,INF=1<<30;

int main(){
    
    /*std::ifstream in("text.txt");
     std::cin.rdbuf(in.rdbuf());*/
    
    int N;cin>>N;
    vector<ll> S(N);
    ll sum=0;
    for(int i=0;i<N;i++){
        cin>>S[i];
        sum+=S[i];
    }
    sort(all(S));
    int cnt=0;
    for(int i=1;i<N;i++){
        if(S[i-1]==S[i]){
            cnt++;
            if(i>=2&&S[i-2]==S[i-1]-1) cnt+=2;
        }
    }
    if(cnt>=2) cout<<"cslnb"<<endl;
    else if(N>=2&&S[1]==0) cout<<"cslnb"<<endl;
    else{
        ll last=(0+(N-1))*N/2;
        if(sum<=last) cout<<"cslnb"<<endl;
        else{
            if((sum-last)%2==1) cout<<"sjfnb"<<endl;
            else cout<<"cslnb"<<endl;
        }
    }
    
}