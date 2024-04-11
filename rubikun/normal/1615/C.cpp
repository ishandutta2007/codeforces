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
        string A,B;cin>>A>>B;
        int s0=0,s1=0,t0=0,t1=0;
        for(int i=0;i<N;i++){
            if(A[i]==B[i]){
                if(A[i]=='1') s1++;
                else s0++;
            }else{
                if(A[i]=='1') t1++;
                else t0++;
            }
        }
        int ans=INF;
        if(t0==t1) chmin(ans,t0+t1);
        if(s1==s0+1) chmin(ans,s0+s1);
        //if(s1==s0-1&&t1) chmin(ans,s0+s1+2);
        if(ans==INF) ans=-1;
        cout<<ans<<"\n";
    }
}