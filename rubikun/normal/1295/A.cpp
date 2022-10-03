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
    
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        if(N%2==0){
            for(int i=0;i<N/2;i++) cout<<1;
        }else{
            cout<<7;
            for(int i=0;i<N/2-1;i++) cout<<1;
        }
        cout<<endl;
    }
}