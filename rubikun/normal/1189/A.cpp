#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2001,INF=1<<30;

int main(){
    
    /*std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());*/
    
    int N;cin>>N;
    string S;cin>>S;
    int cnt=0;
    for(int i=0;i<N;i++){
        if(S[i]=='1') cnt++;
    }
    if(cnt==N-cnt){
        cout<<2<<endl;
        for(int i=0;i<N-1;i++){
            cout<<S[i];
        }
        cout<<" "<<S[N-1]<<endl;
    }else cout<<1<<endl<<S<<endl;
}