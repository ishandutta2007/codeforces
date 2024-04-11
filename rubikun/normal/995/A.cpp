#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<20;

int N;
vector<int> ans1,ans2,ans3;
pair<int,int> mae(int nowi,int nowj){
    if(nowi==1&&nowj==0) return {2,0};
    if(nowi==1) return {1,nowj-1};
    if(nowi==2&&nowj==N-1) return {1,N-1};
    if(nowi==2) return {2,nowj+1};
    
    return {0,0};
}

void solve(int a,int b,int c){
    ans1.push_back(a);
    ans2.push_back(b);
    ans3.push_back(c);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int K;cin>>N>>K;
    vector<vector<int>> S(4,vector<int>(N));
    bool ok=false;
    
    for(int i=0;i<4;i++){
        for(int j=0;j<N;j++){
            cin>>S[i][j];
            if(S[i][j]==0) ok=true;
        }
    }
    
    if(!ok){
        bool an=false;
        for(int i=0;i<4;i+=2){
            for(int j=0;j<N;j++){
                if(S[i][j]==S[i+1][j]) an=true;
            }
        }
        if(!an){
            cout<<-1<<endl;
            return 0;
        }
    }
    
    for(int t=0;t<150;t++){
        
        for(int i=0;i<4;i+=2){
            for(int j=0;j<N;j++){
                if(S[i][j]>=1&&S[i][j]==S[i+1][j]){
                    if(i==0){
                        solve(S[i][j],1,j+1);
                    }
                    else{
                        solve(S[i][j],4,j+1);
                    }
                    
                    S[i][j]=0;
                    S[i+1][j]=0;
                }
            }
        }
        
        vector<vector<int>> to(4,vector<int>(N));
        
        for(int j=0;j<N;j++){
            to[0][j]=S[0][j];
            to[3][j]=S[3][j];
        }
        
        int si,sj;
        
        for(int i=1;i<3;i++){
            for(int j=0;j<N;j++){
                if(S[i][j]==0){
                    si=i;
                    sj=j;
                }
            }
        }
        
        for(int k=0;k<2*N;k++){
            pair<int,int> p=mae(si,sj);
            int a=p.first,b=p.second;
            
            if(S[a][b]){
                solve(S[a][b],si+1,sj+1);
                //cout<<S[a][b]<<" "<<si+1<<" "<<sj+1<<"\n";
            }
            
            to[si][sj]=S[a][b];
            si=a;
            sj=b;
        }
        
        S=to;
    }
    
    cout<<ans1.size()<<endl;
    
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<" "<<ans2[i]<<" "<<ans3[i]<<"\n";
    }
}