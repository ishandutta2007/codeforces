#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int k=0;k<T;k++){
        string S;cin>>S;
        sort(all(S));
        if(S[0]==S[S.size()-1]) cout<<-1<<endl;
        else cout<<S<<endl;
    }
}