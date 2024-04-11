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
        vector<int> A(N),B(N);
        for(int i=0;i<N;i++) cin>>A[i];
        for(int i=0;i<N;i++) cin>>B[i];
        
        int left=-1,right=3*N;
        while(right-left>1){
            int mid=(left+right)/2;
            vector<int> C=A,D=B;
            for(int i=0;i<mid;i++) C.push_back(100);
            for(int i=0;i<mid;i++) D.push_back(0);
            
            sort(all(C));
            sort(all(D));
            reverse(all(C));
            reverse(all(D));
            
            ll sum=0;
            for(int i=0;i<(N+mid)-(N+mid)/4;i++){
                sum+=C[i];
                sum-=D[i];
            }
            if(sum>=0) right=mid;
            else left=mid;
        }
        
        cout<<right<<"\n";
    }
}