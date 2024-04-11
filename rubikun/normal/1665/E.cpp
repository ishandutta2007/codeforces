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
const int mod=1000000007,MAX=3300005,INF=1<<30;

vector<int> G[MAX];
vector<int> X[MAX];
int nex[MAX][2];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int QQ;cin>>QQ;
    memset(nex,-1,sizeof(nex));
    while(QQ--){
        int N;cin>>N;
        vector<int> A(N);
        int sz=1;
        for(int i=0;i<N;i++){
            cin>>A[i];
            int now=0;
            for(int j=29;j>=0;j--){
                if(nex[now][A[i]>>j&1]==-1){
                    G[now].push_back(sz);
                    nex[now][A[i]>>j&1]=sz;
                    now=sz;
                    sz++;
                }else{
                    now=nex[now][A[i]>>j&1];
                }
                X[now].push_back(i);
            }
        }
        
        int Q;cin>>Q;
        while(Q--){
            int l,r;cin>>l>>r;l--;
            int mask=0;
            vector<int> S;
            int now=0;
            
            int ans=INF;
            
            for(int j=29;j>=0;j--){
                int cn=0;
                for(int x:S){
                    if((x>>j&1)==0) cn++;
                }
                if(nex[now][0]!=-1){
                    int to=nex[now][0];
                    cn+=lower_bound(all(X[to]),r)-lower_bound(all(X[to]),l);
                }
                if(cn>=2){
                    vector<int> T;
                    for(int x:S){
                        if((x>>j&1)==0) T.push_back(x);
                    }
                    S=T;
                    if(nex[now][0]==-1) break;
                    else now=nex[now][0];
                }else{
                    mask|=(1<<j);
                    if(nex[now][0]!=-1){
                        int to=nex[now][0];
                        auto it=lower_bound(all(X[to]),l);
                        if(it!=X[to].end()&&(*it)<r) S.push_back(A[*it]);
                    }
                    if(nex[now][1]==-1) break;
                    else now=nex[now][1];
                }
                
                if(j==0){
                    if(lower_bound(all(X[now]),r)-lower_bound(all(X[now]),l)>=2) chmin(ans,mask);
                    if(lower_bound(all(X[now]),r)-lower_bound(all(X[now]),l)>=1){
                        for(int x:S){
                            chmin(ans,mask|x);
                        }
                    }
                }
            }
            
            for(int i=0;i<si(S);i++){
                for(int j=i+1;j<si(S);j++){
                    chmin(ans,S[i]|S[j]);
                }
            }
            cout<<ans<<"\n";
        }
        
        for(int i=0;i<sz;i++){
            G[i].clear();
            nex[i][0]=nex[i][1]=-1;
            X[i].clear();
        }
    }
}