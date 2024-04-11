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
        int H,W;cin>>H>>W;
        vector<int> ma(H*W);
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                chmax(ma[i*W+j],abs(i-0)+abs(j-0));
                chmax(ma[i*W+j],abs(i-0)+abs(j-(W-1)));
                chmax(ma[i*W+j],abs(i-(H-1))+abs(j-0));
                chmax(ma[i*W+j],abs(i-(H-1))+abs(j-(W-1)));
            }
        }
        sort(all(ma));
        for(int i=0;i<H*W;i++) cout<<ma[i]<<" ";
        cout<<"\n";
    }
}