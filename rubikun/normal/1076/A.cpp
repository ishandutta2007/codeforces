#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    string S;cin>>S;
    int ok=-1;
    for(int i=0;i<N-1;i++){
        if(S[i]>S[i+1]){
            ok=i;
            break;
        }
    }
    if(ok!=-1){
        for(int i=0;i<ok;i++){
            cout<<S[i];
        }
        for(int i=ok+1;i<N;i++){
            cout<<S[i];
        }
        cout<<endl;
    }else{
        for(int i=0;i<N-1;i++){
            cout<<S[i];
        }
        cout<<endl;
    }
}