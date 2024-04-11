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
const int mod=1000000007,MAX=1005,INF=1<<30;

char ans[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> p(N);
    int c=-1,r=-1;
    for(int i=0;i<N;i++){
        cin>>p[i];
        p[i]--;
        if(i!=p[i]) chmax(r,i);
    }
    
    if(r==-1){
        cout<<N<<endl;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) cout<<'.';
            cout<<endl;
        }
        return 0;
    }
    
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) ans[i][j]='.';
    
    vector<int> used(N);
    
    int h=N-1;
    
    for(int i=0;i<N;i++) if(p[i]==r) c=i;
    
    int X=p[r];
    
    p[c]=p[r];
    p[r]=r;
    
    for(int t=0;t<r;t++){
        if(used[t]) continue;
        if(t==p[t]) continue;
        
        int now=t;
        bool f=true;
        while(1){
            if(used[now]) break;
            used[now]=1;
            if(f){
                if(p[now]>now){
                    ans[h][now]='/';
                    ans[h][p[now]]='/';
                }else{
                    ans[h][now]='/';
                    ans[h][r]='/';
                    h--;
                    ans[h][r]='\\';
                    ans[h][p[now]]='\\';
                    f=false;
                }
            }else{
                if(p[now]<now){
                    ans[h][now]='\\';
                    ans[h][p[now]]='\\';
                }else{
                    ans[h][now]='\\';
                    ans[h][t]='\\';
                    h--;
                    ans[h][t]='/';
                    ans[h][p[now]]='/';
                    f=true;
                }
            }
            now=p[now];
        }
        h--;
    }
    
    ans[h][X]='/';
    ans[h][r]='/';
    
    cout<<N-1<<endl;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}