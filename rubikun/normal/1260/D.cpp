#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=1<<30;

struct trap{
    int l;
    int r;
    int damage;
};

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int M,N,K,T;cin>>M>>N>>K>>T;
    vector<int> A(M);
    for(int i=0;i<M;i++) cin>>A[i];
    sort(all(A));
    
    vector<trap> B(K);
    for(int i=0;i<K;i++){
        cin>>B[i].l>>B[i].r>>B[i].damage;
    }
    
    vector<int> can(N+2,0);
    for(int i=0;i<K;i++){
        can[B[i].l-1]++;
        can[B[i].r+1]--;
    }
    
    for(int i=1;i<N+2;i++) can[i]+=can[i-1];
    
    bool ok=false;
    int sum=0;
    for(int i=0;i<N+2;i++){
        if(ok){
            if(can[i]) sum+=3;
            else ok=false;
        }else{
            if(can[i]){
                sum+=2;
                ok=true;
            }else sum++;
        }
        
        if(i==0) sum--;
    }
    
    if(sum<=T){
        cout<<M<<endl;
        return 0;
    }
    
    int left=0,right=200005;
    
    while(right-left>1){
        int mid=(left+right)/2;
        
        vector<int> can(N+2,0);
        for(int i=0;i<K;i++){
            if(B[i].damage>mid){
                can[B[i].l-1]++;
                can[B[i].r+1]--;
            }
        }
        
        for(int i=1;i<N+2;i++) can[i]+=can[i-1];
        
        bool ok=false;
        int sum=0;
        for(int i=0;i<N+2;i++){
            if(ok){
                if(can[i]) sum+=3;
                else ok=false;
            }else{
                if(can[i]){
                    sum+=2;
                    ok=true;
                }else sum++;
            }
            
            if(i==0) sum--;
        }
        
        if(sum<=T) right=mid;
        else left=mid;
    }
    
    int ans=0;
    
    for(int i=0;i<M;i++){
        if(A[i]>=right) ans++;
    }
    cout<<ans<<endl;
}