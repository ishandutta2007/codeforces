#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    
    while(T){
        int N,K;cin>>N>>K;
        
        string S;cin>>S;
        vector<int> L,R;
        for(int i=0;i<N;i++){
            if(i%2==0){
                if(S[i]=='(') continue;
                else{
                    for(int j=i+1;j<N;j++){
                        if(S[j]=='('){
                            reverse(S.begin()+i,S.begin()+j+1);
                            L.push_back(i+1);
                            R.push_back(j+1);
                            break;
                        }
                    }
                }
            }else{
                if(S[i]==')') continue;
                else{
                    for(int j=i+1;j<N;j++){
                        if(S[j]==')'){
                            reverse(S.begin()+i,S.begin()+j+1);
                            L.push_back(i+1);
                            R.push_back(j+1);
                            break;
                        }
                    }
                }
            }
        }
        K=(N/2)-K;
        
        for(int i=0;i<K;i++){
            L.push_back(2*i+2);
            R.push_back(2*i+3);
        }
        
        cout<<L.size()<<"\n";
        for(int i=0;i<L.size();i++){
            cout<<L[i]<<" "<<R[i]<<" "<<"\n";
        }
        
        //cout<<S<<endl;
        
        T--;
    }
}