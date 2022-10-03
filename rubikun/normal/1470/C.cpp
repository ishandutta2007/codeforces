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
const int mod=1000000007,MAX=1000005,INF=1<<30;

int main(){
    
    /*std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);*/
    
    int N,K;cin>>N>>K;
    
    if(N<=400){
        for(int t=0;t<N;t++){
            cout<<"? 1"<<endl;
            int x;cin>>x;
        }
        vector<int> A(N);
        for(int t=0;t<N;t++){
            cout<<"? "<<t+1<<endl;
            cin>>A[t];
        }
        
        int ans=-1;
        
        for(int s=0;s<N;s++){
            bool ok=true;
            ok&=(A[s]==K);
            ok&=(A[(s+1)%N]>K);
            ok&=(A[(s+N-1)%N]<K);
            if(ok) ans=s;
        }
        
        cout<<"! "<<ans+1<<endl;
        
        return 0;
    }
    
    int D=sqrt(N)-1;
    
    for(int t=0;t<=D+3;t++){
        cout<<"? 1"<<endl;
        int x;cin>>x;
    }
    
    int ok=-1;
    for(int i=0;i<N;i+=D){
        cout<<"? "<<i+1<<endl;
        int x;cin>>x;
        if(x>K){
            ok=i;
        }
    }
    
    int left=(ok+N-6*D)%N,right=ok;
    
    while((right-left+2*N)%N>1){
        int mid;
        if(left<right) mid=(left+right)/2;
        else mid=((left+right+N)/2)%N;
        
        cout<<"? "<<mid+1<<endl;
        int x;cin>>x;
        if(x>K) right=mid;
        else left=mid;
    }
    
    cout<<"! "<<(right+N-1)%N+1<<endl;
    
    return 0;
    
}