#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    for(int k=0;k<Q;k++){
        int N;cin>>N;
        int sum=0;
        for(int i=0;i<N;i++){
            int a;cin>>a;
            if(a<=2048) sum+=a;
        }
        if(sum>=2048) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}