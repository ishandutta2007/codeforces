#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<ll> A(N);
    vector<int> cnt(60);
    for(int i=0;i<N;i++){
        scanf("%lld",&A[i]);
        //cin>>A[i];
        ll a=A[i];
        for(int k=0;k<60;k++){
            if(a%2==1){
                cnt[k]++;
                break;
            }
            a/=2;
        }
    }
    int maxi=0,point=-1;
    for(int i=0;i<60;i++){
        if(cnt[i]>maxi){
            maxi=cnt[i];
            point=i;
        }
    }
    
    cout<<N-maxi<<endl;
    
    if(N-maxi==0) return 0;
    
    vector<ll> ans;
    
    for(int i=0;i<N;i++){
        ll a=A[i];
        for(int k=0;k<60;k++){
            if(a%2==1){
                if(k!=point) ans.push_back(A[i]);
                break;
            }
            a/=2;
        }
    }
    
    for(int i=0;i<ans.size();i++){
        if(i) printf(" ");
        //cout<<ans[i];
        printf("%lld",ans[i]);
    }
    cout<<endl;
}