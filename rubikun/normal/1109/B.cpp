#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<19,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    if(int(S.size())%2==0){
        if(S.substr(0,S.size()/2)!=S.substr(S.size()/2,S.size()/2)){
            cout<<1<<endl;
        }else{
            set<char> SE;
            for(int i=0;i<S.size();i++){
                SE.insert(S[i]);
            }
            
            if(SE.size()==1) cout<<"Impossible"<<endl;
            else{
                bool ok=false;
                for(int i=1;i<S.size();i++){
                    string T=S.substr(i)+S.substr(0,i);
                    bool check=true;
                    
                    for(int j=0;j<T.size();j++){
                        if(T[j]!=T[T.size()-1-j]) check=false;
                    }
                    
                    if(check&&S!=T) ok=true;
                }
                
                if(ok) cout<<1<<endl;
                else cout<<2<<endl;
            }
        }
    }else{
        set<char> SE;
        for(int i=0;i<int(S.size())/2;i++){
            SE.insert(S[i]);
        }
        
        if(SE.size()==0||SE.size()==1) cout<<"Impossible"<<endl;
        else{
            bool ok=false;
            for(int i=1;i<S.size();i++){
                string T=S.substr(i)+S.substr(0,i);
                bool check=true;
                
                for(int j=0;j<T.size();j++){
                    if(T[j]!=T[T.size()-1-j]) check=false;
                }
                
                if(check&&S!=T) ok=true;
            }
            
            if(ok) cout<<1<<endl;
            else cout<<2<<endl;
        }
    }
    
}