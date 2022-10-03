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
const ll INF=1LL<<60;

vector<int> G[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        for(int i=0;i<N;i++) G[i].clear();
        for(int i=1;i<N;i++){
            int p;cin>>p;p--;
            G[p].push_back(i);
        }
        vector<int> X;
        X.push_back(1);
        for(int i=0;i<N;i++){
            if(si(G[i])) X.push_back(si(G[i]));
        }
        sort(all(X));
        reverse(all(X));
        int ans=si(X);
        int left=ans-1,right=N;
        while(right-left>1){
            int mid=(left+right)/2;
            vector<int> rem(si(X));
            ll sum=0;
            for(int i=0;i<si(X);i++){
                rem[i]=max(0,X[i]-(mid-i));
                sum+=rem[i];
            }
            if(sum<=mid-si(X)) right=mid;
            else left=mid;
        }
        cout<<right<<"\n";
    }
}