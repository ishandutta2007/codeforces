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
const int mod=1000000007,MAX=2000005,INF=1<<30;

const int D=1000000;
pair<int,int> dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<pair<int,int>> A(N),B(N);
    for(int i=0;i<N;i++){
        cin>>A[i].fi;A[i].se=i+1;
    }
    for(int i=0;i<N;i++){
        cin>>B[i].fi;B[i].se=i+1;
    }
    sort(all(A));
    sort(all(B));
    reverse(all(A));
    reverse(all(B));
    int a=0,b=0,now=0;
    memset(dp,-1,sizeof(dp));
    while(1){
        if(dp[now+D].fi!=-1){
            cout<<a-dp[now+D].fi<<"\n";
            for(int i=dp[now+D].fi;i<a;i++) cout<<A[i].se<<" ";
            cout<<"\n";
            cout<<b-dp[now+D].se<<"\n";
            for(int i=dp[now+D].se;i<b;i++) cout<<B[i].se<<" ";
            cout<<"\n";
            return 0;
        }
        dp[now+D]=mp(a,b);
        if(now>0){
            now-=B[b].fi;
            b++;
        }else if(now<0){
            now+=A[a].fi;
            a++;
        }else if(a<N){
            now+=A[a].fi;
            a++;
        }else{
            now-=B[b].fi;
            b++;
        }
    }
}