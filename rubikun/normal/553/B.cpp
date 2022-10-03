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
const int mod=1000000007,MAX=1005;
const ll INF=1LL<<60;

ll comb[55][55];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    comb[0][0]=1;
    for(int i=0;i<=50;i++){
        for(int j=0;j<=i;j++){
            comb[i+1][j]+=comb[i][j];
            comb[i+1][j+1]+=comb[i][j];
        }
    }
    
    int N;ll K;cin>>N>>K;
    vector<int> ans(N);
    
    for(int i=0;i<N;){
        ll sum=0;
        for(int j=0;j<=(N-1-i)/2;j++){
            sum+=comb[N-1-i-j][j];
        }
        if(sum>=K){
            ans[i]=i;
            i++;
        }else{
            ans[i]=i+1;
            ans[i+1]=i;
            K-=sum;
            i+=2;
        }
    }
    
    for(int a:ans) cout<<a+1<<" ";
    cout<<"\n";
}