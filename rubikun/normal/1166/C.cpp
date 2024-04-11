#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<29;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    sort(all(A));
    
    ll ans=0;
    
    for(int a:A){
        if(a<0){
            ans+=(lower_bound(all(A),(a+1)/2)-lower_bound(all(A),a))-1;
            //cout<<ans<<" ";
            ans+=(upper_bound(all(A),abs(-2*a))-lower_bound(all(A),abs(a-1)/2));
        }else{
            ans+=(upper_bound(all(A),2*a)-lower_bound(all(A),a))-1;
        }
        
        //cout<<ans<<endl;
    }
    
    cout<<ans<<endl;
    
}