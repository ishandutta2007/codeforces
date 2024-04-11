#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,x;cin>>N>>x;
        vector<int> A(N);
        int sum=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            sum+=A[i];
        }
        
        sort(all(A));
        
        if(sum==x){
            cout<<"NO\n";
            continue;
        }
        
        cout<<"YES\n";
        
        int now=0;
        
        for(int i=0;i<N;i++){
            if(now+A[i]!=x){
                cout<<A[i]<<" ";
                now+=A[i];
            }else{
                cout<<A[i+1]<<" "<<A[i]<<" ";
                now+=A[i];
                now+=A[i+1];
                i++;
            }
        }
        
        cout<<"\n";
    }
}