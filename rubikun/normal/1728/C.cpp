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
        priority_queue<int> A,B;
        for(int i=0;i<N;i++){
            int x;cin>>x;
            A.push(x);
        }
        for(int i=0;i<N;i++){
            int x;cin>>x;
            B.push(x);
        }
        int ans=0;
        while(!A.empty()){
            int a=A.top(),b=B.top();
            if(a==b){
                A.pop();B.pop();
            }else if(a>b){
                A.pop();
                ans++;
                int cn=0;
                while(a){
                    cn++;
                    a/=10;
                }
                A.push(cn);
            }else{
                B.pop();
                ans++;
                int cn=0;
                while(b){
                    cn++;
                    b/=10;
                }
                B.push(cn);
            }
        }
        
        cout<<ans<<"\n";
    }
    
}