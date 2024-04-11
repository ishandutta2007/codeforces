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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<string> S(N);
        vector<int> cnt(3);
        for(int i=0;i<N;i++) cin>>S[i];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(S[i][j]=='X') cnt[(i+j)%3]++;
            }
        }
        int sum=cnt[0]+cnt[1]+cnt[2];
        
        for(int k=0;k<3;k++){
            if(cnt[k]<=sum/3){
                for(int i=0;i<N;i++){
                    for(int j=0;j<N;j++){
                        if((i+j)%3==k&&S[i][j]=='X') S[i][j]='O';
                    }
                }
                break;
            }
        }
        
        for(int i=0;i<N;i++) cout<<S[i]<<"\n";
    }
}