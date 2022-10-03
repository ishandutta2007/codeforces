#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    string S;cin>>S;
    int N=int(S.size());
    if(N%2){
        bool ok=true;
        for(int i=1;i<N;i++){
            if(S[i]=='1') ok=false;
        }
        if(ok) cout<<N/2<<endl;
        else cout<<N/2+1<<endl;
    }else cout<<N/2<<endl;
}