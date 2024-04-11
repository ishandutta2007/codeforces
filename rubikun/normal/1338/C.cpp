#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    vector<ll> en;
    en.push_back(3);
    
    while(en.back()<=10000000000000000) en.push_back((en.back()+1)*4-1);
    
    int Q;cin>>Q;
    
    while(Q--){
        ll N;cin>>N;
        //N=Q+1;
        //cout<<N<<" "<<A[N]<<" ";
        if(N<=3){
            cout<<N<<"\n";
            continue;
        }
        for(int i=0;i<27;i++){
            if(N<=en[i]){
                ll use=0;
                ll diff=(en[i]-en[i-1])/3;
                
                if(N%3==1){
                    cout<<en[i-1]+(N-en[i-1])/3+1<<"\n";
                }else if(N%3==2){
                    ll num=(N-en[i-1])/3;
                    while(num){
                        if(num<diff/4) {}
                        else if(num<diff/4*2){
                            use+=diff/4*2;
                        }else if(num<diff/4*3){
                            use+=diff/4*3;
                        }else{
                            use+=diff/4;
                        }
                        num%=(diff/4);
                        diff/=4;
                    }
                    cout<<use+en[i-1]+(en[i]-en[i-1])/3+1<<"\n";
                }else{
                    ll num=(N-en[i-1]-1)/3;
                    while(num){
                        if(num<diff/4) {}
                        else if(num<diff/4*2){
                            use+=diff/4*3;
                        }else if(num<diff/4*3){
                            use+=diff/4;
                        }else{
                            use+=diff/4*2;
                        }
                        num%=(diff/4);
                        diff/=4;
                    }
                    cout<<use+en[i-1]+(en[i]-en[i-1])/3*2+1<<"\n";
                }
                break;
            }
        }
    }
}