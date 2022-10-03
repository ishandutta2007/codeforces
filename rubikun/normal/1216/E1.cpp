#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    vector<ll> A(100000,0),sum(100000,INF);
    A[1]=1;
    sum[1]=1;
    for(int i=2;;i++){
        double k=log10(i);
        A[i]=A[i-1]+floor(k)+1;
        sum[i]=sum[i-1]+A[i];
        if(sum[i]>1000000000){
            //cout<<i<<endl;
            break;
        }
        //cout<<A[i]<<" "<<i<<endl;
    }
    sum[0]=0;
    
    string S;
    
    for(int i=1;i<=25000;i++){
        S+=to_string(i);
    }
    
    while(Q--){
        int k;cin>>k;
        int d=lower_bound(all(sum),k)-sum.begin();
        //cout<<d<<endl;
        k-=sum[d-1];
        //cout<<k<<endl;
        cout<<S[k-1]<<endl;
    }
}