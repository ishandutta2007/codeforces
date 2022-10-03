#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    ll N,P;cin>>N>>P;
    if(P<0){
        int cnt=1;
        N-=P;
        while(1){
            int onbit=0;
            for(int i=60;i>=0;i--){
                if(N&(1LL<<i)) onbit++;
            }
            if(onbit<=cnt&&N>=cnt){
                cout<<cnt<<endl;
                return 0;
            }
            
            cnt++;
            N-=P;
        }
    }else if(P>0){
        int cnt=1;
        N-=P;
        while(N>0){
            int onbit=0;
            for(int i=60;i>=0;i--){
                if(N&(1LL<<i)) onbit++;
            }
            if(onbit<=cnt&&N>=cnt){
                cout<<cnt<<endl;
                return 0;
            }
            
            cnt++;
            N-=P;
        }
        
        cout<<-1<<endl;
    }else{
        int onbit=0;
        for(int i=60;i>=0;i--){
            if(N&(1LL<<i)) onbit++;
        }
        cout<<onbit<<endl;
    }
}