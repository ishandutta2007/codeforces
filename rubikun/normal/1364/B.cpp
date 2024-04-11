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
        int N;cin>>N;
        vector<int> A(N),ans;
        for(int i=0;i<N;i++) cin>>A[i];
        
        ans.push_back(A[0]);
        
        for(int i=0;i<N;i++){
            if(i==N-1){
                //ans.push_back(A[i]);
                break;
            }
            int j=i+1;
            if(A[i]<A[j]){
                while(j<N&&A[j-1]<A[j]) j++;
                j--;
                ans.push_back(A[j]);
                i=j-1;
            }else{
                while(j<N&&A[j-1]>A[j]) j++;
                j--;
                ans.push_back(A[j]);
                i=j-1;
            }
        }
        
        cout<<si(ans)<<"\n";
        for(int a:ans) cout<<a<<" ";
        cout<<"\n";
        
        
    }
}