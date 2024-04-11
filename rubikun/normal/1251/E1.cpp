#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003;
const ll INF=1LL<<60;

bool compare(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int Q;cin>>Q;
    
    while(Q){
        int N;cin>>N;
        ll ans=0;
        int cnt=0;
        priority_queue<int,vector<int>,greater<int>> PQ;
        vector<pair<int,int>> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i].first>>A[i].second;
        }
        sort(all(A),compare);
        
        for(int i=0;i<N;i++){
            if(A[i].first-cnt<=N-i-1){
                PQ.push(A[i].second);
            }else{
                PQ.push(A[i].second);
                ans+=ll(PQ.top());PQ.pop();
                cnt++;
            }
        }
        
        cout<<ans<<endl;
        
        Q--;
    }
}