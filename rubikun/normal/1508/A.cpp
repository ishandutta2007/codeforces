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
        vector<string> S(3);
        for(int i=0;i<3;i++) cin>>S[i];
        vector<int> cnt(3);
        
        for(int i=0;i<3;i++){
            for(char c:S[i]) if(c=='0') cnt[i]++;
        }
        
        string res;
        
        for(int i=0;i<3;i++){
            for(int j=i+1;j<3;j++){
                if(cnt[i]>=N&&cnt[j]>=N&&si(res)==0){
                    int x=0,y=0;
                    while(x<2*N||y<2*N){
                        if(x>=2*N){
                            res+=S[j][y];
                            y++;
                        }else if(y>=2*N){
                            res+=S[i][x];
                            x++;
                        }else{
                            if(S[i][x]==S[j][y]){
                                res+=S[i][x];
                                x++;
                                y++;
                            }else{
                                res+='1';
                                if(S[i][x]=='1') x++;
                                if(S[j][y]=='1') y++;
                            }
                        }
                    }
                }
            }
        }
        
        for(int i=0;i<3;i++){
            for(int j=i+1;j<3;j++){
                if(cnt[i]<N&&cnt[j]<N&&si(res)==0){
                    int x=0,y=0;
                    while(x<2*N||y<2*N){
                        if(x>=2*N){
                            res+=S[j][y];
                            y++;
                        }else if(y>=2*N){
                            res+=S[i][x];
                            x++;
                        }else{
                            if(S[i][x]==S[j][y]){
                                res+=S[i][x];
                                x++;
                                y++;
                            }else{
                                res+='0';
                                if(S[i][x]=='0') x++;
                                if(S[j][y]=='0') y++;
                            }
                        }
                    }
                }
            }
        }
        
        cout<<res<<"\n";
    }
}