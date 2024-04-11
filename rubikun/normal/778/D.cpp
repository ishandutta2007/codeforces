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
const int mod=998244353,MAX=300005,INF=1<<30;

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    vector<string> S(H),T(H);
    for(int i=0;i<H;i++) cin>>S[i];
    for(int i=0;i<H;i++) cin>>T[i];
    
    auto check=[&](vector<string> A){
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(A[i][j]=='L'){
                    if(j+1>=W){
                        cout<<-1<<"\n";
                        exit(0);
                    }
                    if(A[i][j+1]!='R'){
                        cout<<-1<<"\n";
                        exit(0);
                    }
                }
                if(A[i][j]=='R'){
                    if(j==0){
                        cout<<-1<<"\n";
                        exit(0);
                    }
                    if(A[i][j-1]!='L'){
                        cout<<-1<<"\n";
                        exit(0);
                    }
                }
                if(A[i][j]=='U'){
                    if(i+1>=H){
                        cout<<-1<<"\n";
                        exit(0);
                    }
                    if(A[i+1][j]!='D'){
                        cout<<-1<<"\n";
                        exit(0);
                    }
                }
                if(A[i][j]=='D'){
                    if(i==0){
                        cout<<-1<<"\n";
                        exit(0);
                    }
                    if(A[i-1][j]!='U'){
                        cout<<-1<<"\n";
                        exit(0);
                    }
                }
            }
        }
    };
    
    check(S);
    check(T);
    
    auto solve1=[&](vector<string> &A){
        vector<pair<int,int>> res;
        for(int j=0;j<W;j++){
            for(int i=0;i<H;i++){
                if((i&1)&&(A[i][j]=='D')) continue;
                if((!(i&1))&&(A[i][j]=='U')) continue;
                assert(A[i][j]=='L');
                vector<pair<int,int>> yaru;
                for(int k=0;;k++){
                    yaru.push_back(mp(i+k,j+k));
                    if(A[i+k][j+k]=='L'&&A[i+k][j+k+1]=='R'&&A[i+k+1][j+k]=='L'&&A[i+k+1][j+k+1]=='R'){
                        while(!yaru.empty()){
                            res.push_back(yaru.back());
                            int h=yaru.back().fi,w=yaru.back().se;
                            if(A[h][w]=='L'){
                                A[h][w]=A[h][w+1]='U';
                                A[h+1][w]=A[h+1][w+1]='D';
                            }else{
                                A[h][w]=A[h+1][w]='L';
                                A[h][w+1]=A[h+1][w+1]='R';
                            }
                            yaru.pop_back();
                        }
                        break;
                    }
                    yaru.push_back(mp(i+k+1,j+k));
                    if(A[i+k+1][j+k]=='U'&&A[i+k+1][j+k+1]=='U'&&A[i+k+2][j+k]=='D'&&A[i+k+2][j+k+1]=='D'){
                        while(!yaru.empty()){
                            res.push_back(yaru.back());
                            int h=yaru.back().fi,w=yaru.back().se;
                            if(A[h][w]=='L'){
                                A[h][w]=A[h][w+1]='U';
                                A[h+1][w]=A[h+1][w+1]='D';
                            }else{
                                A[h][w]=A[h+1][w]='L';
                                A[h][w+1]=A[h+1][w+1]='R';
                            }
                            yaru.pop_back();
                        }
                        break;
                    }
                }
            }
        }
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(i&1) assert(A[i][j]=='D');
                else assert(A[i][j]=='U');
            }
        }
        
        return res;
    };
    
    auto solve2=[&](vector<string> &A){
        vector<pair<int,int>> res;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if((j&1)&&(A[i][j]=='R')) continue;
                if((!(j&1))&&(A[i][j]=='L')) continue;
                assert(A[i][j]=='U');
                vector<pair<int,int>> yaru;
                for(int k=0;;k++){
                    yaru.push_back(mp(i+k,j+k));
                    if(A[i+k][j+k]=='U'&&A[i+k][j+k+1]=='U'&&A[i+k+1][j+k]=='D'&&A[i+k+1][j+k+1]=='D'){
                        while(!yaru.empty()){
                            res.push_back(yaru.back());
                            int h=yaru.back().fi,w=yaru.back().se;
                            if(A[h][w]=='L'){
                                A[h][w]=A[h][w+1]='U';
                                A[h+1][w]=A[h+1][w+1]='D';
                            }else{
                                A[h][w]=A[h+1][w]='L';
                                A[h][w+1]=A[h+1][w+1]='R';
                            }
                            yaru.pop_back();
                        }
                        break;
                    }
                    yaru.push_back(mp(i+k,j+k+1));
                    if(A[i+k][j+k+1]=='L'&&A[i+k][j+k+2]=='R'&&A[i+k+1][j+k+1]=='L'&&A[i+k+1][j+k+2]=='R'){
                        while(!yaru.empty()){
                            res.push_back(yaru.back());
                            int h=yaru.back().fi,w=yaru.back().se;
                            if(A[h][w]=='L'){
                                A[h][w]=A[h][w+1]='U';
                                A[h+1][w]=A[h+1][w+1]='D';
                            }else{
                                A[h][w]=A[h+1][w]='L';
                                A[h][w+1]=A[h+1][w+1]='R';
                            }
                            yaru.pop_back();
                        }
                        break;
                    }
                }
            }
        }
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(j&1) assert(A[i][j]=='R');
                else assert(A[i][j]=='L');
            }
        }
        
        return res;
    };
    
    if(H%2==0){
        vector<pair<int,int>> res1=solve1(S),res2=solve1(T);
        reverse(all(res2));
        
        vector<pair<int,int>> ans;
        for(auto a:res1) ans.push_back(a);
        for(auto a:res2) ans.push_back(a);
        
        if(S!=T){
            cout<<-1<<"\n";
            return 0;
        }
        
        cout<<si(ans)<<"\n";
        for(auto a:ans) cout<<a.fi+1<<" "<<a.se+1<<"\n";
    }else{
        vector<pair<int,int>> res1=solve2(S),res2=solve2(T);
        reverse(all(res2));
        
        vector<pair<int,int>> ans;
        for(auto a:res1) ans.push_back(a);
        for(auto a:res2) ans.push_back(a);
        
        if(S!=T){
            cout<<-1<<"\n";
            return 0;
        }
        
        cout<<si(ans)<<"\n";
        for(auto a:ans) cout<<a.fi+1<<" "<<a.se+1<<"\n";
    }
}