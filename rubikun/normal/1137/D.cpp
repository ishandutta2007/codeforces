#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string A="next 0",B="next 0 1",C="next 0 1 2 3 4 5 6 7 8 9",D="done";
    
    while(1){
        cout<<A<<endl;
        int K;cin>>K;
        for(int i=0;i<K;i++){
            int a;
            cin>>a;
        }
        cout<<B<<endl;
        cin>>K;
        for(int i=0;i<K;i++){
            int a;
            cin>>a;
        }
        if(K==2) break;
    }
    
    while(1){
        cout<<C<<endl;
        int K;cin>>K;
        for(int i=0;i<K;i++){
            int a;
            cin>>a;
        }
        if(K==1) break;
    }
    cout<<D<<endl;
}