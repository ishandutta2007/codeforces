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
const int mod=998244353,MAX=3005,INF=1<<29;

int dp[2][1<<20];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    vector<string> S(H);
    for(int i=0;i<H;i++) cin>>S[i];
    vector<vector<int>> A(H,vector<int>(W));
    for(int i=0;i<H;i++) for(int j=0;j<W;j++) cin>>A[i][j];
    for(int i=0;i<2;i++) for(int j=0;j<(1<<H);j++) dp[i][j]=INF;
    dp[0][0]=0;
    
    vector<pair<int,int>> B;
    map<int,int> MA;
    
    for(int j=0;j<W;j++){
        vector<pair<char,int>> T(H);
        for(int i=0;i<H;i++) T[i]=mp(S[i][j],i);
        sort(all(T));
        int i=0;
        while(i<H){
            int k=i;
            while(k<H&&T[i].fi==T[k].fi) k++;
            int sum=0,mask=0,ma=0;
            for(int l=i;l<k;l++){
                int x=T[l].se;
                if(MA.count(1<<x)) chmin(MA[1<<x],A[x][j]);
                else MA[1<<x]=A[x][j];
                //B.push_back(mp(A[x][j],(1<<x)));
                sum+=A[x][j];
                mask|=(1<<x);
                chmax(ma,A[x][j]);
            }
            //B.push_back(mp(sum-ma,mask));
            if(MA.count(mask)) chmin(MA[mask],sum-ma);
            else MA[mask]=sum-ma;
            
            i=k;
        }
    }
    
    for(auto a:MA) B.push_back(mp(a.se,a.fi));
    
    sort(all(B));
    
    for(int i=0;i<si(B);i++){
        int s=i&1,t=s^1;
        for(int j=0;j<(1<<H);j++){
            chmin(dp[t][j|B[i].se],dp[s][j]+B[i].fi);
            chmin(dp[t][j],dp[s][j]);
            dp[s][j]=INF;
        }
    }
    
    cout<<dp[si(B)&1][(1<<H)-1]<<endl;
}