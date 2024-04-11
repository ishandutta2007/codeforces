#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    while(Q){
        int N,A,B,C;cin>>N>>A>>C>>B;
        string S;cin>>S;
        int win=0;
        
        vector<char> T(N,'Q');
        for(int i=0;i<N;i++){
            if(S[i]=='R'){
                if(C){
                    T[i]='P';
                    C--;
                    win++;
                }
            }else if(S[i]=='S'){
                if(A){
                    T[i]='R';
                    A--;
                    win++;
                }
            }else if(S[i]=='P'){
                if(B){
                    T[i]='S';
                    B--;
                    win++;
                }
            }
        }
        
        if(win>=(N+1)/2){
            cout<<"YES"<<endl;
            for(int i=0;i<N;i++){
                if(T[i]=='Q'){
                    if(A){
                        T[i]='R';
                        A--;
                    }else if(B){
                        T[i]='S';
                        B--;
                    }else{
                        T[i]='P';
                        C--;
                    }
                }
                cout<<T[i];
            }
            cout<<endl;
        }else cout<<"NO"<<endl;
        
        Q--;
        
    }
    
}