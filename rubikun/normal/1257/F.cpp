#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000003,MAX=200003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    map<vector<int>,int> MA;
    
    for(int bit=0;bit<(1<<15);bit++){
        vector<int> diff(N,0);
        for(int i=0;i<N;i++){
            int a=A[i]%(1<<15);
            diff[i]=__builtin_popcount(a^bit);
        }
        
        MA[diff]=bit+1;
    }
    
    for(int bit=0;bit<(1<<15);bit++){
        vector<int> diff(N,0);
        for(int i=0;i<N;i++){
            int a=A[i]/(1<<15);
            diff[i]=__builtin_popcount(a^bit);
        }
        
        for(int k=0;k<=30;k++){
            vector<int> left(N,0);
            for(int i=0;i<N;i++) left[i]=k-diff[i];
            if(MA[left]!=0){
                cout<<bit*(1<<15)+MA[left]-1<<endl;
                return 0;
            }
        }
    }
    
    cout<<-1<<endl;
}