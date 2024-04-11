#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    string S;cin>>S;
    for(int i=0;i<N-1;i++){
        if(S[i]!=S[i+1]){
            cout<<"YES"<<endl;
            cout<<S[i]<<S[i+1]<<endl;
            break;
        }
        if(i==N-2) cout<<"NO"<<endl;
    }
    if(N==1) cout<<"NO"<<endl;
}