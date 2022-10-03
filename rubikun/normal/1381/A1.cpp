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
        string A,B;cin>>A>>B;
        vector<int> ans;
        for(int i=N-1;i>=0;i--){
            if(A[i]==B[i]) continue;
            
            if(A[0]==B[i]){
                ans.push_back(0);
                if(A[0]=='0') A[0]='1';
                else A[0]='0';
            }
            
            ans.push_back(i);
            for(int j=0;j<=i;j++){
                if(A[j]=='0') A[j]='1';
                else A[j]='0';
            }
            reverse(A.begin(),A.begin()+i+1);
        }
        
        cout<<si(ans)<<" ";
        for(int a:ans) cout<<a+1<<" ";
        cout<<"\n";
    }
}