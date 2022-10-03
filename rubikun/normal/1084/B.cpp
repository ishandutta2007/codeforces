#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=10003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;ll S;cin>>N>>S;
    vector<ll> A(N);
    ll sum=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        sum+=A[i];
    }
    
    if(sum<S){
        cout<<-1<<endl;
        return 0;
    }
    
    sort(all(A));
    
    ll left=0,right=A[0]+1;
    
    while(right-left>1){
        ll mid=(left+right)/2;
        ll ryou=0;
        for(int i=0;i<N;i++){
            if(A[i]-mid>=0) ryou+=A[i]-mid;
        }
        if(ryou>=S) left=mid;
        else right=mid;
    }
    
    cout<<left<<endl;
}