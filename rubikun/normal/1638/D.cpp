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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    vector<vector<int>> S(H,vector<int>(W)),seen(H,vector<int>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>S[i][j];
        }
    }
    queue<pair<int,int>> Q;
    vector<vector<int>> ans;
    for(int i=0;i+1<H;i++){
        for(int j=0;j+1<W;j++){
            set<int> SE;
            for(int k=i;k<=i+1;k++){
                for(int l=j;l<=j+1;l++){
                    SE.insert(S[k][l]);
                }
            }
            if(si(SE)==1){
                seen[i][j]=true;
                Q.push(mp(i,j));
            }
        }
    }
    
    while(!Q.empty()){
        auto u=Q.front();Q.pop();
        int x=-1;
        int i=u.fi,j=u.se;
        for(int k=i;k<=i+1;k++){
            for(int l=j;l<=j+1;l++){
                if(S[k][l]!=-1) x=S[k][l];
                S[k][l]=-1;
            }
        }
        if(x!=-1){
            ans.push_back({i+1,j+1,x});
        }
        
        for(int s=i-1;s<=i+1;s++){
            for(int t=j-1;t<=j+1;t++){
                if(s<0||s==H-1) continue;
                if(t<0||t==W-1) continue;
                if(seen[s][t]) continue;
                set<int> SE;
                for(int k=s;k<=s+1;k++){
                    for(int l=t;l<=t+1;l++){
                        if(S[k][l]!=-1) SE.insert(S[k][l]);
                    }
                }
                if(si(SE)<=1){
                    Q.push(mp(s,t));
                    seen[s][t]=true;
                }
            }
        }
    }
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]!=-1){
                cout<<-1<<"\n";
                return 0;
            }
        }
    }
    
    reverse(all(ans));
    
    cout<<si(ans)<<"\n";
    for(auto a:ans){
        for(int b:a) cout<<b<<" ";
        cout<<"\n";
    }
}