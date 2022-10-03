#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=200001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    string S;cin>>S;
    int cnt=0;
    for(int i=0;i<N-10;i++){
        if(S[i]=='8') cnt++;
    }
    if(cnt>(N-11)/2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    
    
}