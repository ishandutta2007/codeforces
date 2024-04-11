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

vector<int> dh={0,0,1,1},dw={0,1,0,1};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int H,W;cin>>H>>W;
        vector<string> S(H);
        int cn=0;
        for(int i=0;i<H;i++){
            cin>>S[i];
            for(int j=0;j<W;j++){
                if(S[i][j]=='1') cn++;
            }
        }
        
        if(cn==0){
            cout<<0<<"\n";
            continue;
        }
        
        int mi=3;
        for(int i=0;i<H-1;i++){
            for(int j=0;j<W-1;j++){
                for(int m=0;m<4;m++){
                    int de=0;
                    for(int k=0;k<4;k++){
                        if(m==k) continue;
                        if(S[i+dh[k]][j+dw[k]]=='1') de++;
                    }
                    if(de) chmin(mi,de);
                }
            }
        }
        
        mi--;
        
        cout<<cn-mi<<"\n";
    }
}