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
const int mod=1000000007,MAX=105,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<string> S(N);
    vector<int> use(26),nex(26,-1),par(26,-1);
    for(int i=0;i<N;i++){
        cin>>S[i];
        vector<int> cnt(26);
        for(char c:S[i]){
            cnt[int(c-'a')]++;
            use[int(c-'a')]=true;
        }
        for(int j=0;j<26;j++){
            if(cnt[j]>=2){
                cout<<"NO\n";
                return 0;
            }
        }
        
        for(int j=0;j+1<si(S[i]);j++){
            int a=S[i][j]-'a',b=S[i][j+1]-'a';
            if(nex[a]>=0&&nex[a]!=b){
                cout<<"NO\n";
                return 0;
            }
            nex[a]=b;
            if(par[b]>=0&&par[b]!=a){
                cout<<"NO\n";
                return 0;
            }
            par[b]=a;
        }
    }
    
    string ans;
    for(int i=0;i<26;i++){
        if(use[i]&&par[i]==-1){
            int now=i;
            while(now!=-1){
                ans+=char('a'+now);
                now=nex[now];
            }
        }
    }
    
    for(int i=0;i<N;i++){
        int cnt=0;
        for(int j=0;j+si(S[i])-1<si(ans);j++){
            string U=ans.substr(j,si(S[i]));
            if(U==S[i]) cnt++;
        }
        if(cnt!=1){
            cout<<"NO\n";
            return 0;
        }
    }
    
    cout<<ans<<"\n";
}