#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        string S;cin>>S;
        bool ok=true;
        
        for(int i=0;i<N/2;i++){
            if(abs(S[i]-S[N-1-i])!=0&&abs(S[i]-S[N-1-i])!=2) ok=false;
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}