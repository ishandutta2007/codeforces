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
    
    int Q;cin>>Q;
    while(Q--){
        int N;string S;cin>>N>>S;
        string A,B;
        A+='1';
        B+='1';
        
        for(int i=1;i<N;i++){
            if(S[i]=='0'){
                A+='0';
                B+='0';
            }else if(S[i]=='1'){
                A+='1';
                B+='0';
                break;
            }else{
                A+='1';
                B+='1';
            }
        }
        
        for(int i=int(A.size());i<N;i++){
            if(S[i]=='0'){
                A+='0';
                B+='0';
            }else if(S[i]=='1'){
                A+='0';
                B+='1';
            }else{
                A+='0';
                B+='2';
            }
        }
        
        cout<<A<<"\n";
        cout<<B<<"\n";
    }
}