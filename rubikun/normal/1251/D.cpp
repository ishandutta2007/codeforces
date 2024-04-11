#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003;
const ll INF=1LL<<60;

bool compare(pair<ll,ll> a,pair<ll,ll> b){
    return a.first>b.first;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    
    while(Q){
        ll N,S;//cin>>N>>S;
        scanf("%lld",&N);
        scanf("%lld",&S);
        vector<pair<ll,ll>> A(N);
        ll need=0;
        for(int i=0;i<N;i++){
            //cin>>A[i].first>>A[i].second;
            scanf("%lld",&A[i].first);
            scanf("%lld",&A[i].second);
            need+=A[i].first;
        }
        sort(all(A),compare);
        ll left=A[N/2].first,right=INF;
        
        while(right-left>1){
            ll mid=(left+right)/2;
            int cnt=0;
            ll sum=need;
            
            for(int i=0;i<N;i++){
                if(A[i].second<mid) continue;
                
                if(A[i].first>=mid) cnt++;
                else if(sum+mid-A[i].first<=S){
                    sum+=mid-A[i].first;
                    cnt++;
                }
            }
            
            if(cnt>N/2) left=mid;
            else right=mid;
        }
        
        
        printf("%lld\n",left);
        //cout<<left<<endl;
        
        Q--;
    }
}