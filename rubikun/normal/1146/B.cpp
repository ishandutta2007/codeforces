#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S,T;cin>>T;
    bool ok=true;
    for(int i=0;i<T.size();i++){
        if(T[i]!='a') S+=T[i];
    }
    
    if(int(S.size())%2==1) ok=false;
    else{
        for(int i=0;i<S.size()/2;i++){
            if(S[i]!=S[i+int(S.size())/2]) ok=false;
        }
    }
    
    reverse(all(T));
    
    for(int i=0;i<int(S.size())/2;i++) if(T[i]=='a') ok=false;
    
    reverse(all(T));
    
    if(ok){
        cout<<T.substr(0,T.size()-int(S.size())/2)<<endl;
    }else cout<<":("<<endl;
    
    
}