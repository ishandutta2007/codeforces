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
//const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> B(N);
    for(int i=0;i<N;i++) cin>>B[i];
    
    if(N==2){
        if(B[0]==B[1]){
            if(B[0]==0){
                cout<<"YES"<<endl;
                cout<<"1 1"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            if(B[0]<B[1]){
                cout<<"YES"<<endl;
                cout<<B[0]+B[1]<<" "<<B[1]<<endl;
            }else{
                cout<<"YES"<<endl;
                cout<<B[0]<<" "<<B[0]+B[1]<<endl;
            }
        }
    }else{
        set<ll> SE;
        for(int i=0;i<N;i++) SE.insert(B[i]);
        
        if(si(SE)==1){
            if(B[0]==0){
                cout<<"YES"<<endl;
                for(int i=0;i<N;i++) cout<<1<<" ";
                cout<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            vector<ll> A(N);
            cout<<"YES"<<endl;
            int t=-1;
            for(int i=0;i<N;i++){
                if(B[i]<B[(i+1)%N]){
                    t=i;
                    break;
                }
            }
            
            A[t]=1000000000000000LL/B[(t+1)%N]*B[(t+1)%N]+B[t];
            for(int i=1;i<N-1;i++){
                A[(t+N-i)%N]=A[(t+N-(i-1))%N]+B[(t+N-i)%N];
            }
            A[(t+1)%N]=B[(t+1)%N];
            
            for(auto x:A) cout<<x<<" ";
            cout<<endl;
        }
    }
}