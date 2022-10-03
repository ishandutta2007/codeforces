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
    
    int N,K;cin>>N>>K;
    K=240-K;
    int cnt=0;
    for(int i=1;i<=N;i++){
        if(5*i<=K){
            K-=5*i;
            cnt++;
        }
    }
    
    cout<<cnt<<endl;
}