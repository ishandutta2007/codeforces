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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<vector<char>> S(3*N,vector<char>(3*N,'x')),ans(2*N-1,vector<char>(2*N-1,'.')),T;
    
    for(int i=N;i<N+N;i++){
        for(int j=N;j<N+N;j++){
            cin>>S[i][j];
        }
    }
    
    T=S;
    
    for(int i=0;i<3*N;i++){
        for(int j=0;j<3*N;j++){
            if(T[i][j]=='x') T[i][j]='.';
        }
    }
    
    for(int i=0;i<2*N-1;i++){
        for(int j=0;j<2*N-1;j++){
            int dh=i-(N-1),dw=j-(N-1);
            if(dh==0&&dw==0){
                ans[i][j]='o';
                continue;
            }
            bool ok=true;
            
            for(int h=N;h<N+N;h++){
                for(int w=N;w<N+N;w++){
                    if(S[h][w]=='o'){
                        if(S[h+dh][w+dw]=='.') ok=false;
                    }
                }
            }
            
            if(ok) ans[i][j]='x';
        }
    }
    
    for(int i=N;i<N+N;i++){
        for(int j=N;j<N+N;j++){
            if(T[i][j]=='o'){
                for(int h=0;h<2*N-1;h++){
                    for(int w=0;w<2*N-1;w++){
                        if(ans[h][w]!='x') continue;
                        int dh=h-(N-1),dw=w-(N-1);
                        if(T[i+dh][j+dw]!='o') T[i+dh][j+dw]='x';
                    }
                }
            }
        }
    }
    
    /*for(int i=0;i<2*N-1;i++){
        for(int j=0;j<2*N-1;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }*/
    
    bool ok=true;
    
    for(int i=N;i<N+N;i++){
        for(int j=N;j<N+N;j++){
            if(S[i][j]!=T[i][j]) ok=false;
            //cout<<T[i][j];
        }
        //cout<<endl;
    }
    
    if(ok){
        cout<<"YES"<<endl;
        for(int i=0;i<2*N-1;i++){
            for(int j=0;j<2*N-1;j++){
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }else{
        cout<<"NO"<<endl;
    }
}