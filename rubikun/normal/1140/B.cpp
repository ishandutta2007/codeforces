#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000003,MAX=200001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    for(int k=0;k<N;k++){
        int M;cin>>M;
        string S;cin>>S;
        int cnt=INF;
        for(int i=0;i<M;i++){
            if(S[i]=='>'){
                cnt=i;
                break;
            }
        }
        for(int i=M-1;i>=0;i--){
            if(S[i]=='<'){
                cnt=min(cnt,M-1-i);
                break;
            }
        }
        cout<<cnt<<endl;
    }
}