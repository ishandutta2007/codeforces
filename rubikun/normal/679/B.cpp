#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    vector<ll> A={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    vector<ll> B={0,1,2,3,4,5,6,7,15,23,50,114,330,1330,10591,215970,19464802,16542386125,409477218238718,2000000000000000};
    
    ll M;cin>>M;
    for(int i=0;i<20;i++){
        if(B[i]==M){
            cout<<A[i]<<" "<<B[i]<<endl;
            return 0;
        }
        if(B[i+1]>M){
            cout<<A[i]<<" ";
            ll now=200000;
            int rem=A[i];
            ll can=M;
            ll sum=0;
            
            while(rem){
                while(1){
                    if(rem&&now*now*now<=can){
                        if(can-now*now*now>=B[rem-1]){
                            can-=now*now*now;
                            sum+=now*now*now;
                            rem--;
                        }else{
                            can=now*now*now-1;
                        }
                    }else break;
                }
                now--;
            }
            cout<<sum<<endl;
            
            return 0;
        }
    }
}