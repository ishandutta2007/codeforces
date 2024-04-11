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

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N),B(N);
        for(int i=0;i<N;i++) cin>>A[i]>>B[i];
        int left=0,right=N+1;
        while(right-left>1){
            int mid=(left+right)/2;
            int cnt=0;
            for(int i=0;i<N;i++){
                if(A[i]>=mid-cnt-1&&B[i]>=cnt) cnt++;
                if(cnt>=mid) break;
            }
            if(cnt>=mid) left=mid;
            else right=mid;
        }
        cout<<left<<"\n";
    }
}