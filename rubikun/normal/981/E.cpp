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
const int mod1=1000000007,mod2=1000000009,MAX=10005,INF=1<<30;

vector<int> A[MAX],B[MAX];
ll dp1[MAX],dp2[MAX];

void mul(int a){
    for(int i=10000;i>=a;i--){
        dp1[i]+=dp1[i-a];
        dp2[i]+=dp2[i-a];
        if(dp1[i]>=mod1) dp1[i]-=mod1;
        if(dp2[i]>=mod2) dp2[i]-=mod2;
    }
}

void div(int a){
    for(int i=a;i<=10000;i++){
        dp1[i]-=dp1[i-a];
        dp2[i]-=dp2[i-a];
        if(dp1[i]<0) dp1[i]+=mod1;
        if(dp2[i]<0) dp2[i]+=mod2;
    }
}//

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,Q;cin>>N>>Q;
    for(int q=0;q<Q;q++){
        int l,r,x;cin>>l>>r>>x;
        l--;r--;
        A[l].push_back(x);
        B[r].push_back(x);
    }
    dp1[0]=dp2[0]=1;
    
    vector<int> ans(N+1);
    
    for(int t=0;t<N;t++){
        for(int a:A[t]) mul(a);
        for(int i=1;i<=N;i++){
            if(dp1[i]&&dp2[i]) ans[i]=true;
        }
        for(int a:B[t]) div(a);
    }
    
    set<int> res;
    for(int i=1;i<=N;i++) if(ans[i]) res.insert(i);
    
    cout<<si(res)<<endl;
    for(int a:res) cout<<a<<" ";
    cout<<endl;
}