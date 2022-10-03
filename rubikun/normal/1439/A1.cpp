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

vector<pair<int,int>> ans;
vector<string> S;

void que(int h,int w){
    ans.push_back(mp(h,w));
    if(S[h][w]=='0') S[h][w]='1';
    else S[h][w]='0';
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int H,W;cin>>H>>W;
        S.resize(H);
        for(int i=0;i<H;i++){
            cin>>S[i];
        }
        
        ans.clear();
        
        if(H&1){
            for(int j=0;j+1<W;j++){
                if(S[H-1][j]=='0'){
                    if(S[H-1][j+1]=='0') continue;
                    que(H-2,j);
                    que(H-2,j+1);
                    que(H-1,j+1);
                }else{
                    if(S[H-1][j+1]=='0'){
                        que(H-2,j);
                        que(H-2,j+1);
                        que(H-1,j);
                    }else{
                        que(H-2,j);
                        que(H-1,j);
                        que(H-1,j+1);
                    }
                }
            }
        }
        
        if(W&1){
            for(int i=0;i+1<H;i++){
                if(S[i][W-1]=='0'){
                    if(S[i+1][W-1]=='0') continue;
                    que(i,W-2);
                    que(i+1,W-2);
                    que(i+1,W-1);
                }else{
                    if(S[i+1][W-1]=='0'){
                        que(i,W-2);
                        que(i+1,W-2);
                        que(i,W-1);
                    }else{
                        que(i,W-2);
                        que(i,W-1);
                        que(i+1,W-1);
                    }
                }
            }
        }
        
        for(int i=0;i+1<H;i+=2){
            for(int j=0;j+1<W;j+=2){
                int cnt=0;
                if(S[i][j]=='1') cnt++;
                if(S[i][j+1]=='1') cnt++;
                if(S[i+1][j]=='1') cnt++;
                if(S[i+1][j+1]=='1') cnt++;
                
                if(cnt==0) continue;
                
                if(cnt==4){
                    que(i,j);
                    que(i,j+1);
                    que(i+1,j);
                    
                    que(i,j+1);
                    que(i+1,j);
                    que(i+1,j+1);
                    
                    que(i+1,j);
                    que(i+1,j+1);
                    que(i,j);
                    
                    que(i+1,j+1);
                    que(i,j);
                    que(i,j+1);
                    
                    continue;
                }
                
                if(cnt==1){
                    int ok=0;
                    for(int a=i;a<=i+1;a++){
                        for(int b=j;b<=j+1;b++){
                            if(S[a][b]=='1') que(a,b);
                            else{
                                if(ok<2){
                                    que(a,b);
                                    ok++;
                                }
                            }
                        }
                    }
                }
                
                if(cnt<=2){
                    bool ok=false;
                    for(int a=i;a<=i+1;a++){
                        for(int b=j;b<=j+1;b++){
                            if(S[a][b]=='0') que(a,b);
                            else{
                                if(!ok){
                                    que(a,b);
                                    ok=true;
                                }
                            }
                        }
                    }
                    
                    for(int a=i;a<=i+1;a++){
                        for(int b=j;b<=j+1;b++){
                            if(S[a][b]=='1') que(a,b);
                        }
                    }
                }
                
                if(cnt<=3){
                    for(int a=i;a<=i+1;a++){
                        for(int b=j;b<=j+1;b++){
                            if(S[a][b]=='1') que(a,b);
                        }
                    }
                }
            }
        }
        
        cout<<si(ans)/3<<"\n";
        
        for(int i=0;i<si(ans);i+=3){
            cout<<ans[i].fi+1<<" "<<ans[i].se+1<<" ";
            cout<<ans[i+1].fi+1<<" "<<ans[i+1].se+1<<" ";
            cout<<ans[i+2].fi+1<<" "<<ans[i+2].se+1<<" ";
            
            cout<<"\n";
        }
    }
}