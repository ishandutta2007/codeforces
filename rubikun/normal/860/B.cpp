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
const int mod=1000000007,MAX=3005,INF=1<<29;

map<int,int> MA[10];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N;i++){
        string S;cin>>S;
        for(int j=0;j<9;j++){
            int now=0;
            for(int k=j;k<9;k++){
                now*=10;
                now+=int(S[k]-'0');
                if(MA[k-j+1].count(now)){
                    if(MA[k-j+1][now]!=i) MA[k-j+1][now]=-1;
                }else{
                    MA[k-j+1][now]=i;
                }
            }
        }
    }
    
    vector<pair<int,int>> ans(N,mp(INF,INF));
    
    for(int len=9;len>=1;len--){
        for(auto a:MA[len]){
            //cout<<a.fi<<" "<<a.se<<" "<<len<<endl;
            if(a.se==-1) continue;
            ans[a.se]=mp(len,a.fi);
        }
    }
    
    for(int i=0;i<N;i++){
        string res=to_string(ans[i].se);
        while(si(res)<ans[i].fi) res='0'+res;
        cout<<res<<"\n";
    }
}