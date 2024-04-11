#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    string S;cin>>S;
    int N=S.size();
    vector<int> ok(N,0);
    char mini=S[0];
    for(int i=1;i<N;i++){
        if(mini<S[i]){
            ok[i]=1;
        }else mini=S[i];
    }
    
    for(int i=0;i<N;i++){
        if(ok[i]) cout<<"Ann";
        else cout<<"Mike";
        cout<<"\n";
    }
    
}