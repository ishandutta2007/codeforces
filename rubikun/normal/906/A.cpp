#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;
bool may[MAX];
int cnt=0;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<26;i++){
        may[i]=1;
        cnt++;
    }
    
    int ans=0;
    
    while(N--){
        char c;cin>>c;
        string S;cin>>S;
        vector<int> can(26);
        for(int i=0;i<si(S);i++){
            can[S[i]-'a']=1;
        }
        if(c=='!'){
            if(cnt==1) ans++;
            else{
                for(int i=0;i<26;i++){
                    if(may[i]&&!can[i]){
                        may[i]=0;
                        cnt--;
                    }
                }
            }
        }else if(c=='.'){
            for(int i=0;i<26;i++){
                if(may[i]&&can[i]){
                    may[i]=0;
                    cnt--;
                }
            }
        }else{
            if(!N) continue;
            if(cnt==1) ans++;
            for(int i=0;i<26;i++){
                if(may[i]&&can[i]){
                    may[i]=0;
                    cnt--;
                }
            }
        }
    }
    
    cout<<ans<<endl;
}