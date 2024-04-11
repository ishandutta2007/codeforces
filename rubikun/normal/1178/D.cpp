#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=2003,INF=1<<30;

int prime[MAX];//i
bool is_prime[MAX+1];

void sieve(int n){
    int p=0;
    for(int i=0;i<=n;i++){
        is_prime[i]=true;
    }
    
    is_prime[0]=is_prime[1]=false;
    
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime[p++] = i;
            for(int j=2*i;j<=n;j+=i){
                is_prime[j] = false;
            }
        }
    }
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    sieve(2000);
    int N;cin>>N;
    if(N==3){
        cout<<3<<endl;
        cout<<"1 2"<<endl;
        cout<<"2 3"<<endl;
        cout<<"1 3"<<endl;
    }else if(N==4){
        cout<<5<<endl;
        cout<<"1 2"<<endl;
        cout<<"1 3"<<endl;
        cout<<"2 3"<<endl;
        cout<<"2 4"<<endl;
        cout<<"3 4"<<endl;
    }else{
        if(is_prime[N]){
            cout<<N<<endl;
            for(int i=1;i<N;i++){
                cout<<i<<" "<<i+1<<endl;
            }
            cout<<N<<" "<<1<<endl;
        }else{
            for(int to=N+1;to<=2*N;to++){
                if(is_prime[to]){
                    cout<<to<<endl;
                    for(int i=1;i<N;i++){
                        cout<<i<<" "<<i+1<<endl;
                    }
                    cout<<N<<" "<<1<<endl;
                    for(int i=1;i<=to-N;i++){
                        cout<<i<<" "<<i+N/2<<endl;
                    }
                    return 0;
                }
            }
        }
    }
}