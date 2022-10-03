#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,I;cin>>N>>I;
    vector<int> A(N+1),B;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    A[N]=INF;
    sort(all(A));
    int cnt=1;
    for(int i=1;i<=N;i++){
        if(A[i]==A[i-1]) cnt++;
        else{
            B.push_back(cnt);
            cnt=1;
        }
    }
    
    int m=I*8/N;
    if(m>=20) cout<<0<<endl;
    else{
        int bor=(1<<m);
        int ans=0;
        int BS=int(B.size());
        vector<int> sum(BS+1,0);
        for(int i=0;i<BS;i++){
            sum[i+1]=sum[i]+B[i];
        }
        if(bor>=BS) ans=N;
        for(int i=0;i<BS;i++){
            if(i+bor>BS) continue;
            ans=max(ans,sum[i+bor]-sum[i]);
        }
        cout<<N-ans<<endl;
    }
    
}