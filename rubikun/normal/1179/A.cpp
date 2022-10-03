#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18;
const ll INF=1LL<<40;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,Q;cin>>N>>Q;
    deque<int> DQ(N);
    int maxi=-1;
    for(int i=0;i<N;i++){
        cin>>DQ[i];
        maxi=max(maxi,DQ[i]);
    }
    vector<int> A(N+1),B(N+1);
    int now=1;
    for(now;;now++){
        int a=DQ[0],b=DQ[1];
        A[now]=a,B[now]=b;
        DQ.pop_front();DQ.pop_front();
        if(a<=b) swap(a,b);
        DQ.push_front(a);
        DQ.push_back(b);
        
        if(a==maxi||b==maxi) break;
    }
    
    while(Q--){
        ll k;cin>>k;
        if(k<=now) cout<<A[k]<<" "<<B[k]<<"\n";
        else{
            ll rem=(k-now-1)%(N-1)+1;
            cout<<DQ[0]<<" "<<DQ[rem]<<"\n";
        }
    }
}