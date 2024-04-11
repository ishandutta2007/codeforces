#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    string S;cin>>S;
    int cn1=0,cn0=0;
    for(int i=0;i<N;i++){
        if(S[i]=='z') cn0++;
        else if(S[i]=='n') cn1++;
    }
    
    for(int i=0;i<cn0+cn1;i++){
        if(i) cout<<" ";
        if(i<cn1) cout<<1;
        else cout<<0;
    }
    cout<<endl;
    
}