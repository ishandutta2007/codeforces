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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<50;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,A,B,K;cin>>N>>A>>B>>K;
    string S;cin>>S;
    vector<int> ans;
    int cnt=0;
    for(int i=0;i<N;i++){
        if(S[i]=='1') cnt=0;
        else{
            cnt++;
            if(cnt==B){
                ans.push_back(i+1);
                cnt=0;
            }
        }
    }
    cout<<si(ans)-A+1<<endl;
    for(int i=0;i<si(ans)-A+1;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}