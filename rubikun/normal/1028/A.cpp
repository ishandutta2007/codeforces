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
//const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    vector<string> S(H);
    for(int i=0;i<H;i++) cin>>S[i];
    
    set<int> h,w;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]=='B'){
                h.insert(i);
                w.insert(j);
            }
        }
    }
    
    cout<<(*h.begin()+*h.rbegin())/2+1<<" "<<(*w.begin()+*w.rbegin())/2+1<<endl;
}