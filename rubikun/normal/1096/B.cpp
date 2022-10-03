#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    string S;cin>>S;
    int l=-1,r=0;//0l-1r+1N-1
    for(int j=N-2;j>=0;j--){
        if(S[j]!=S[N-1]){
            r=j;
            break;
        }
    }
    for(int j=1;j<N;j++){
        if(S[j]!=S[0]){
            l=j;
            break;
        }
    }
    
    ll sum=0;
    
    for(int i=0;i<N;i++){
        if(i==0) sum+=N-r;
        else{
            if(S[0]==S[N-1]){
                if(l<i) continue;
                sum+=N-r;
            }else{
                if(l<i) continue;
                sum++;
            }
        }
    }
    
    cout<<sum%mod<<endl;
}