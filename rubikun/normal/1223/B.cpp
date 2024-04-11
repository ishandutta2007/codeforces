#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    while(Q){
        string S,T;cin>>S>>T;
        bool ans=false;
        for(int i=0;i<26;i++){
            bool ok1=false,ok2=false;
            for(char k:S){
                if(k==char('a'+i)) ok1=true;
            }
            for(char k:T){
                if(k==char('a'+i)) ok2=true;
            }
            if(ok1&&ok2) ans=true;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
        Q--;
    }
}