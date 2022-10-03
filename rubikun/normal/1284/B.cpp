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
    vector<int> ok(N),mini(N,INF),maxi(N,0),cnt(1000007,0);
    int s=0;
    
    for(int i=0;i<N;i++){
        int l;cin>>l;
        vector<int> A(l);
        for(int j=0;j<l;j++){
            cin>>A[j];
            mini[i]=min(mini[i],A[j]);
            maxi[i]=max(maxi[i],A[j]);
        }
        vector<int> B=A;
        sort(all(B));
        reverse(all(B));
        if(A!=B){
            ok[i]=1;
            s++;
        }
        
        if(ok[i]==0) cnt[maxi[i]]++;
    }
    
    for(int i=1;i<=1000003;i++) cnt[i]+=cnt[i-1];
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        if(ok[i]) ans+=N;
        else{
            ans+=s;
            ans+=ll(cnt[1000003]-cnt[mini[i]]);
            //cout<<cnt[1000003]<<" "<<cnt[mini[i]]<<endl;
        }
        
        //cout<<ans<<endl;
    }
    
    cout<<ans<<endl;
    
}