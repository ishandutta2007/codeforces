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
const int mod=1000000007,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        string S;cin>>S;
        int ans=INF;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<=min(N-1,i+6);j++){
                int a=0,b=0,c=0;
                for(int k=i;k<=j;k++){
                    if(S[k]=='a') a++;
                    if(S[k]=='b') b++;
                    if(S[k]=='c') c++;
                }
                if(a>b&&a>c) chmin(ans,j-i+1);
            }
        }
        
        if(ans==INF) ans=-1;
        cout<<ans<<"\n";
    }
}