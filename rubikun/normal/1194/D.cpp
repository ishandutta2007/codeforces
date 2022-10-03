#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    for(int i=0;i<Q;i++){
        int n,k;cin>>n>>k;
        if(k%3==0){
            n%=(k+1);
            if(n%3==0&&n!=k) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }else{
            if(n%3==0) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
    }
}