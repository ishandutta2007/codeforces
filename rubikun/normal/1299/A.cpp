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
    vector<pair<ll,ll>> A(N);
    vector<int> cnt(50);
    for(int i=0;i<N;i++){
        cin>>A[i].second;
        for(int j=0;j<50;j++){
            if(A[i].second&(1LL<<j)) cnt[j]++;
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<50;j++){
            if((A[i].second&(1LL<<j))&&cnt[j]==1) A[i].first+=(1LL<<j);
        }
    }
    sort(all(A));
    reverse(all(A));
    
    for(int i=0;i<N;i++){
        cout<<A[i].second<<" ";
    }
    cout<<endl;
}