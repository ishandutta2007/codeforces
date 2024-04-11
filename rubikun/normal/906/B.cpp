#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H,W;cin>>H>>W;
    bool change=false;
    if(H>W){
        swap(H,W);
        change=true;
    }
    
    vector<vector<int>> S(H,vector<int>(W)),T(W,vector<int>(H));
    
    if(W==1){
        cout<<"YES"<<endl;
        cout<<1<<endl;
    }else if(W==2){
        cout<<"NO"<<endl;
    }else if(W==3){
        if(H<=2){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            cout<<"8 1 6\n";
            cout<<"3 5 7\n";
            cout<<"4 9 2\n";
        }
    }else if(W%2==0){
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(j<W/2) S[i][j]=i*W+(j+1)*2;
                else S[i][j]=i*W+(j-W/2)*2+1;
            }
            if(i%2==1) reverse(all(S[i]));
        }
        
        if(change){
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    T[W-1-j][i]=S[i][j];
                }
            }
            
            vector<int> to(H*W);
            for(int i=0;i<H*W;i++){
                int a=i/W,b=i%W;
                to[i]=a+(W-1-b)*H;
            }
            cout<<"YES\n";
            
            for(int i=0;i<W;i++){
                for(int j=0;j<H;j++){
                    cout<<to[T[i][j]-1]+1<<" ";
                }
                cout<<endl;
            }
        }else{
            cout<<"YES\n";
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    cout<<S[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }else{
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(j<W/2) S[i][j]=i*W+(j+1)*2;
                else S[i][j]=i*W+(j-W/2)*2+1;
            }
            if(i%2==1){
                int save=S[i][W-1];
                for(int j=W-1;j>=1;j--) S[i][j]=S[i][j-1];
                S[i][0]=save;
            }
        }
        
        if(change){
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    T[W-1-j][i]=S[i][j];
                }
            }
            
            vector<int> to(H*W);
            for(int i=0;i<H*W;i++){
                int a=i/W,b=i%W;
                to[i]=a+(W-1-b)*H;
            }
            
            cout<<"YES\n";
            
            for(int i=0;i<W;i++){
                for(int j=0;j<H;j++){
                    cout<<to[T[i][j]-1]+1<<" ";
                }
                cout<<endl;
            }
        }else{
            cout<<"YES\n";
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    cout<<S[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
}