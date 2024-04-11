#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N/2);
    vector<ll> ans(N);
    ll sum=0;
    
    for(int i=0;i<N/2;i++) cin>>A[i];
    
    for(int i=0;i<N/2;i++){
        for(int j=sqrt(A[i]);j>=1;j--){
            if(A[i]%j==0){
                if(j%2==A[i]/j%2){
                    ll a=(A[i]/j-j)/2,b=(A[i]/j+j)/2;
                    if(sum<a*a){
                        ans[i*2]=a*a-sum;
                        ans[i*2+1]=A[i];
                        sum=b*b;
                        break;
                    }
                }
            }
        }
    }
    
    bool ok=true;
    
    for(int i=0;i<N;i++) if(ans[i]==0) ok=false;
    
    if(ok){
        cout<<"Yes"<<endl;
        for(ll a:ans) cout<<a<<" ";
        cout<<endl;
    }else cout<<"No"<<endl;
}