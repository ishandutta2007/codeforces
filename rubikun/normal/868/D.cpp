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
const int mod=1000000007,MAX=12,INF=1<<28;

struct dat{
    string pre;
    string suf;
    vector<vector<int>> deta;
    
    void init(string A){
        if(si(A)<=12){
            pre=A;
            suf=A;
        }else{
            pre=A.substr(0,12);
            suf=A.substr(si(A)-12);
        }
        deta.resize(13);
        for(int i=1;i<=12;i++){
            deta[i].resize(1<<i);
            for(int j=0;j+(i-1)<si(A);j++){
                int x=0;
                for(int k=j;k<j+i;k++){
                    x*=2;
                    x+=int(A[k]-'0');
                }
                deta[i][x]=1;
            }
        }
    }
    
    int merge(dat A,dat B){
        deta.resize(13);
        for(int i=1;i<=12;i++){
            deta[i].resize(1<<i);
        }
        
        if(si(A.pre)==12) pre=A.pre;
        else{
            pre=A.pre+B.pre;
            if(si(pre)>12) pre=pre.substr(0,12);
        }
        
        if(si(B.suf)==12) suf=B.suf;
        else{
            suf=A.suf+B.suf;
            if(si(suf)>12) suf=suf.substr(si(suf)-12);
        }
        for(int i=1;i<=12;i++){
            string X=A.suf+B.pre;
            for(int j=0;j+(i-1)<si(X);j++){
                int x=0;
                for(int k=j;k<j+i;k++){
                    x*=2;
                    x+=int(X[k]-'0');
                }
                deta[i][x]=1;
            }
            for(int j=0;j<si(deta[i]);j++){
                chmax(deta[i][j],A.deta[i][j]);
                chmax(deta[i][j],B.deta[i][j]);
            }
        }
        for(int i=1;i<=12;i++){
            int sum=0;
            for(int j=0;j<si(deta[i]);j++) sum+=deta[i][j];
            if(sum<si(deta[i])) return i-1;
        }
        
        return -1;
    }
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    vector<dat> S(200);
    
    int N;cin>>N;
    for(int i=0;i<N;i++){
        string T;cin>>T;
        S[i].init(T);
    }
    
    int M;cin>>M;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        cout<<S[N+i].merge(S[a],S[b])<<"\n";
    }
}