#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1003,INF=1<<30;

int dp[MAX][53][53];
struct KMP{
    vector<int> A;
    vector<vector<int>> nex;
    string S;
    
    void init(string &T){
        S=T;
        A.assign(S.size()+1,0);
        nex.assign(S.size()+1,vector<int>(26,0));
        A[0]=-1;
        int j=-1;
        
        for(int i=0;i<S.size();i++){
            while(j>=0&&S[i]!=S[j]) j=A[j];
            j++;
            
            A[i+1]=j;
        }
        
        for(int i=0;i<=S.size();i++){
            for(int c=0;c<26;c++){
                int j=i;
                
                while(j>=0&&S[j]!=char('a'+c)) j=A[j];
                j++;
                
                nex[i][c]=j;
            }
        }
    }
    
    vector<int> match(string &C,string &T){
        init(C);
        vector<int> B;
        int m=0,i=0;
        
        while(m+i<T.size()){
            if(S[i]==T[m+i]){
                i++;
                if(i==S.size()){
                    B.push_back(m);
                    m+=i-A[i];
                    i=A[i];
                }
            }else{
                m+=i-A[i];
                if(i>0) i=A[i];
            }
        }
        
        return B;
    }//CT
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string C,S,T;cin>>C>>S>>T;
    KMP s,t;
    s.init(S);
    t.init(T);
    
    for(int i=0;i<=C.size();i++){
        for(int j=0;j<=S.size();j++){
            for(int k=0;k<=T.size();k++){
                dp[i][j][k]=-INF;
            }
        }
    }
    dp[0][0][0]=0;
    
    for(int i=0;i<C.size();i++){
        for(int j=0;j<=S.size();j++){
            for(int k=0;k<=T.size();k++){
                if(dp[i][j][k]==-INF) continue;
                
                if(C[i]!='*'){
                    int a=s.nex[j][C[i]-'a'],b=t.nex[k][C[i]-'a'];
                    int cnt=0;
                    if(a==S.size()) cnt++;
                    if(b==T.size()) cnt--;
                    
                    dp[i+1][a][b]=max(dp[i+1][a][b],dp[i][j][k]+cnt);
                }else{
                    for(int z=0;z<26;z++){
                        int a=s.nex[j][z],b=t.nex[k][z];
                        int cnt=0;
                        if(a==S.size()) cnt++;
                        if(b==T.size()) cnt--;
                        
                        dp[i+1][a][b]=max(dp[i+1][a][b],dp[i][j][k]+cnt);
                    }
                }
            }
        }
    }
    
    int ans=-INF;
    
    for(int j=0;j<=S.size();j++){
        for(int k=0;k<=T.size();k++){
            ans=max(ans,dp[C.size()][j][k]);
        }
    }
    
    cout<<ans<<endl;
}