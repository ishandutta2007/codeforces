#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    for(int k=0;k<T;k++){
        int N;ll X;cin>>N>>X;
        vector<ll> d(N),h(N);
        ll maxd=-1,maxdiff=-1;
        for(int i=0;i<N;i++){
            cin>>d[i]>>h[i];
            maxd=max(maxd,d[i]);
            maxdiff=max(maxdiff,d[i]-h[i]);
        }
        if(maxdiff<=0){
            if(maxd>=X) cout<<1<<endl;
            else cout<<-1<<endl;
        }else{
            X-=maxd;
            if(X<=0) cout<<1<<endl;
            else cout<<1+(X+maxdiff-1)/maxdiff<<endl;
        }
    }
}