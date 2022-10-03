#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=1<<19,INF=1LL<<32;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    ll ans=0,kakeru=1;
    stack<int> ST;
    for(int i=0;i<N;i++){
        string S;cin>>S;
        if(S=="add"){
            if(kakeru>=INF){
                ans=INF;
                break;
            }
            ans+=kakeru;
        }else if(S=="end"){
            int a=ST.top();ST.pop();
            kakeru/=a;
        }else{
            int a;cin>>a;
            if(kakeru<=INF){
                kakeru*=a;
                ST.push(a);
            }else{
                ST.push(1);
            }
        }
    }
    if(ans>=INF) cout<<"OVERFLOW!!!"<<endl;
    else cout<<ans<<endl;
    
}