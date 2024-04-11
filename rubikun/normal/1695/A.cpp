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
        int H,W;cin>>H>>W;
        int ma=-INF;
        int h=-1,w=-1;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                int x;cin>>x;
                if(chmax(ma,x)){
                    h=i;
                    w=j;
                }
            }
        }
        cout<<max((h+1),H-h)*max((w+1),(W-w))<<"\n";
    }
}