#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<29;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    
    while(Q){
        string S;cin>>S;
        string A,B;
        for(int i=0;i<S.size();i++){
            if((S[i]-'0')%2==0) A+=S[i];
            else B+=S[i];
        }
        string T;
        int a=0,b=0;
        while(a<A.size()&&b<B.size()){
            if(A[a]<B[b]){
                T+=A[a];
                a++;
            }else{
                T+=B[b];
                b++;
            }
        }
        
        while(a<A.size()){
            T+=A[a];
            a++;
        }
        
        while(b<B.size()){
            T+=B[b];
            b++;
        }
        
        cout<<T<<endl;
        
        Q--;
    }
}