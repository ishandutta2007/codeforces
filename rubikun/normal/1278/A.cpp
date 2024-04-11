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
    
    int T;cin>>T;
    while(T--){
        string A,B;cin>>A>>B;
        sort(all(A));
        bool ok=false;
        for(int i=0;i+A.size()<=B.size();i++){
            string BB=B;
            sort(B.begin()+i,B.begin()+i+A.size());
            
            if(A==B.substr(i,A.size())) ok=true;
            
            B=BB;
        }
        
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}