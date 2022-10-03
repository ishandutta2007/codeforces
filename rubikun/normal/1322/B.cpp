#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    int ans=0;
    
    for(int bi=0;bi<25;bi++){
        vector<int> B(N);
        for(int i=0;i<N;i++){
            B[i]=A[i]&((1<<(bi+1))-1);
        }
        sort(all(B));
        
        ll cnt=0;
        
        for(int i=0;i<N;i++){
            cnt+=(lower_bound(all(B),(1<<(bi+1))-B[i])-B.begin());
            cnt-=(lower_bound(all(B),(1<<bi)-B[i])-B.begin());
            
            cnt+=(lower_bound(all(B),(1<<(bi+2))-B[i])-B.begin());
            cnt-=(lower_bound(all(B),(1<<(bi+1))+(1<<bi)-B[i])-B.begin());
            if((B[i]*2)&(1<<bi)) cnt--;
            
            //cout<<cnt<<" ";
        }
        
        cnt/=2;
        
        if(cnt&1) ans+=(1<<bi);
        
        //cout<<cnt<<endl;
    }
    
    cout<<ans<<endl;
    
    
}