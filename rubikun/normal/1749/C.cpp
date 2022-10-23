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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        sort(all(A));
        int cn=0;
        for(int a:A) if(a==1) cn++;
        
        if(A[0]>1){
            cout<<0<<"\n";
            continue;
        }
        int left=1,right=min(cn+1,(N+3)/2);
        while(right-left>1){
            int mid=(left+right)/2;
            bool ok=true;
            for(int i=2;i<=mid;i++){
                ok&=(A[mid+i-2]<=i);
            }
            if(ok) left=mid;
            else right=mid;
        }
        
        cout<<left<<"\n";
    }
}