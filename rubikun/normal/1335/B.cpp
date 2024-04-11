#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,A,B;cin>>N>>A>>B;
        string S;
        while(S.size()<N){
            for(int i=0;i<B-1;i++) S+=char('a'+i);
            for(int i=0;i<=A-B;i++) S+=char('a'+B-1);
        }
        
        for(int i=0;i<N;i++){
            cout<<S[i];
        }
        cout<<"\n";
    }
}