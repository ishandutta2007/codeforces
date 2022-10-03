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
        string S;cin>>S;
        S+=S;
        S+=S;
        
        int ans=0;
        
        for(int i=N;i<2*N;i++){
            if(S[i]=='R'&&S[i+1]=='L'){
                int j=i-1;
                while(j>=0&&S[j]=='R') j--;
                ans+=(i-j)/3;
                j=i+2;
                while(j<4*N&&S[j]=='L') j++;
                ans+=(j-(i+1))/3;
            }
        }
        
        int cnt1=0,cnt2=0;
        
        for(int i=N;i<2*N;i++){
            if(S[i]=='R') cnt1++;
            if(S[i]=='L') cnt2++;
        }
        
        if(cnt1==0||cnt2==0){
            ans=(N+2)/3;
        }
        
        cout<<ans<<"\n";
    }
}