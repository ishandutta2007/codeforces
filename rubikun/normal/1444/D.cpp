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
const int mod=998244353,MAX=505,INF=1<<30;

bool dp[505][250005];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int H,W;
        cin>>H;
        vector<int> A(H);
        int hsum=0,wsum=0;
        for(int i=0;i<H;i++){
            cin>>A[i];
            hsum+=A[i];
        }
        cin>>W;
        vector<int> B(W);
        for(int i=0;i<W;i++){
            cin>>B[i];
            wsum+=B[i];
        }
        
        sort(all(A));
        sort(all(B));
        
        if(H!=W||(hsum&1)||(wsum&1)){
            cout<<"No\n";
            continue;
        }
        
        //cout<<H<<" "<<W<<endl;
        
        for(int i=0;i<=H;i++) for(int j=0;j<=hsum/2;j++) dp[i][j]=0;
        
        dp[0][0]=1;
        
        int sum=0;
        
        for(int i=0;i<H;i++){
            for(int j=0;j<=min(sum,hsum/2);j++){
                if(j+A[i]<=hsum/2) dp[i+1][j+A[i]]|=dp[i][j];
                dp[i+1][j]|=dp[i][j];
            }
            sum+=A[i];
        }
        
        vector<int> use1,use2;
        
        if(dp[H][hsum/2]==0){
            cout<<"No\n";
            continue;
        }
        
        int nowi=H,nowj=hsum/2;
        while(nowi){
            if(dp[nowi-1][nowj]){
                nowi--;
                use2.push_back(A[nowi]);
            }else{
                nowi--;
                nowj-=A[nowi];
                use1.push_back(A[nowi]);
            }
        }
        
        reverse(all(use1));
        reverse(all(use2));
        
        for(int i=0;i<=W;i++) for(int j=0;j<=wsum/2;j++) dp[i][j]=0;
        
        dp[0][0]=1;
        
        sum=0;
        
        for(int i=0;i<W;i++){
            for(int j=0;j<=min(sum,wsum/2);j++){
                if(j+B[i]<=wsum/2) dp[i+1][j+B[i]]|=dp[i][j];
                dp[i+1][j]|=dp[i][j];
            }
            sum+=B[i];
        }
        
        vector<int> use3,use4;
        
        if(dp[W][wsum/2]==0){
            cout<<"No\n";
            continue;
        }
        
        nowi=W;nowj=wsum/2;
        while(nowi){
            if(dp[nowi-1][nowj]){
                nowi--;
                use4.push_back(B[nowi]);
            }else{
                nowi--;
                nowj-=B[nowi];
                use3.push_back(B[nowi]);
            }
        }
        
        reverse(all(use3));
        reverse(all(use4));
        
        bool done=false;
        
        for(int q=0;q<64;q++){
            vector<int> X,Y;
            
            vector<pair<int,int>> ans;
            
            ans.push_back(mp(0,0));
            
            if(q&1){
                for(int a:use1) X.push_back(a);
                for(int a:use2) X.push_back(a);
            }else{
                for(int a:use2) X.push_back(a);
                for(int a:use1) X.push_back(a);
            }
            
            if(q&2){
                for(int a:use3) Y.push_back(a);
                for(int a:use4) Y.push_back(a);
            }else{
                for(int a:use4) Y.push_back(a);
                for(int a:use3) Y.push_back(a);
            }
            
            bool t1=false,t2=false;
            
            for(int k=0;k<H;k++){
                auto last=ans.back();
                if(t1){
                    ans.push_back(mp(last.fi-X[k],last.se));
                }else{
                    ans.push_back(mp(last.fi+X[k],last.se));
                    if(ans.back().fi==hsum/2) t1=true;
                }
                
                last=ans.back();
                if(t2){
                    ans.push_back(mp(last.fi,last.se-Y[k]));
                }else{
                    ans.push_back(mp(last.fi,last.se+Y[k]));
                    if(ans.back().se==wsum/2) t2=true;
                }
            }
            
            bool ok=true;
            
            for(int i=0;i<si(ans)-1;i+=2){
                for(int j=1;j<si(ans)-1;j+=2){
                    auto a=ans[i],b=ans[i+1],c=ans[j],d=ans[j+1];
                    if(a.fi>b.fi) swap(a,b);
                    if(c.se>d.se) swap(c,d);
                    
                    if(a==c||a==d||b==c||b==d) continue;
                    
                    if(a.fi<=c.fi&&c.fi<=b.fi&&c.se<=a.se&&a.se<=d.se) ok=false;
                    if(!ok) break;
                }
                if(!ok) break;
            }
            
            if(ok){
                ans.pop_back();
                done=true;
                
                cout<<"Yes\n";
                for(auto x:ans) cout<<x.fi<<" "<<x.se<<"\n";
            }
            if(done) break;
            
            if(q&3) reverse(all(use1));
            if(q&7) reverse(all(use2));
            if(q&15) reverse(all(use3));
            if(q&31) reverse(all(use4));
        }
        
        if(!done) cout<<"No"<<endl;
    }
}