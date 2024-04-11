#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        if(N==1){
            cout<<-1<<"\n";
        }else{
            cout<<2;
            for(int i=0;i<N-1;i++){
                cout<<3;
            }
            cout<<"\n";
        }
    }
}