#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=(((1<<30)-1)<<1)+1;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    //int i=0;
    while(Q){
        ll X,Y,K;cin>>X>>Y>>K;
        /*X=x[i];
        Y=y[i];
        K=k[i];
        cout<<X<<" "<<Y<<" "<<K<<" ";*/
        if(abs(X)>K||abs(Y)>K){
            cout<<-1<<endl;
        }else{
            if((abs(X)+abs(Y))%2==0){
                if(abs(X)%2!=K%2) cout<<K-2<<endl;
                else cout<<K<<endl;
            }else if(max(abs(X),abs(Y))==K){
                if(min(abs(X),abs(Y))%2!=(K-1)%2) cout<<K-3<<endl;
                else cout<<K-1<<endl;
            }else{
                cout<<K-1<<endl;
            }
        }
        
        Q--;
        //i++;
    }
}