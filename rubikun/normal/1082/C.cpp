#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1<<18,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    vector<int> A[M],ans(N,0);
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;a--;
        A[a].push_back(b);
    }
    
    for(int i=0;i<M;i++){
        sort(all(A[i]));
        reverse(all(A[i]));
        int sum=0;
        for(int j=0;j<A[i].size();j++){
            sum+=A[i][j];
            if(sum<=0) break;
            ans[j]+=sum;
        }
    }
    
    int k=0;
    
    for(int i=0;i<N;i++){
        k=max(k,ans[i]);
    }
    
    cout<<k<<endl;
    
}