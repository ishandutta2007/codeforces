#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=500003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int k=0;k<T;k++){
        int N;string S;cin>>N>>S;
        int ans=INF;
        for(int i=N-1;i>=0;i--){
            if(S[i]=='8') ans=i;
        }
        if(N-ans>=11) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}