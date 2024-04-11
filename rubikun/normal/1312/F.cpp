#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1005,INF=1<<25;

ll dp[MAX][3][6][6][6],roop[3][6][6][6];

struct KMP{
    vector<int> A;
    string S;
    
    void init(string &T){
        S=T;
        A.assign(S.size()+1,0);
        A[0]=-1;
        int j=-1;
        
        for(int i=0;i<S.size();i++){
            while(j>=0&&S[i]!=S[j]) j=A[j];
            j++;
            
            A[i+1]=j;
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
    }//C(=S)T
};


int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    for(int x=1;x<=5;x++){
        for(int y=1;y<=5;y++){
            for(int z=1;z<=5;z++){
                dp[0][0][x][y][z]=dp[0][1][x][y][z]=dp[0][2][x][y][z]=0;
                
                for(int i=1;i<=800;i++){
                    set<ll> SE;
                    if(i-x<=0) SE.insert(0);
                    else SE.insert(dp[i-x][0][x][y][z]);
                    
                    if(i-y<=0) SE.insert(0);
                    else SE.insert(dp[i-y][1][x][y][z]);
                    
                    if(i-z<=0) SE.insert(0);
                    else SE.insert(dp[i-z][2][x][y][z]);
                    
                    for(int j=0;j<=5;j++){
                        if(SE.find(j)==SE.end()){
                            dp[i][0][x][y][z]=j;
                            break;
                        }
                    }
                    
                    SE.clear();
                    
                    if(i-x<=0) SE.insert(0);
                    else SE.insert(dp[i-x][0][x][y][z]);
                    
                    if(i-z<=0) SE.insert(0);
                    else SE.insert(dp[i-z][2][x][y][z]);
                    
                    for(int j=0;j<=5;j++){
                        if(SE.find(j)==SE.end()){
                            dp[i][1][x][y][z]=j;
                            break;
                        }
                    }
                    
                    SE.clear();
                    
                    if(i-x<=0) SE.insert(0);
                    else SE.insert(dp[i-x][0][x][y][z]);
                    
                    if(i-y<=0) SE.insert(0);
                    else SE.insert(dp[i-y][1][x][y][z]);
                    
                    for(int j=0;j<=5;j++){
                        if(SE.find(j)==SE.end()){
                            dp[i][2][x][y][z]=j;
                            break;
                        }
                    }
                }
                
                for(int j=0;j<3;j++){
                    
                    string S;
                    
                    for(int i=105;i<=800;i++){
                        S+=char('0'+dp[i][j][x][y][z]);
                    }
                    
                    KMP kmp;
                    kmp.init(S);
                    
                    roop[j][x][y][z]=300-kmp.A[300];
                }
            }
        }
    }
    
    int Q;cin>>Q;
    while(Q--){
        int N,X,Y,Z;cin>>N>>X>>Y>>Z;
        vector<int> att={X,Y,Z};
        vector<ll> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        
        ll grundy=0;
        
        for(int i=0;i<N;i++){
            if(A[i]<=200){
                grundy^=dp[A[i]][0][X][Y][Z];
            }else{
                ll a=A[i];
                a-=(A[i]-200)/roop[0][X][Y][Z]*roop[0][X][Y][Z];
                grundy^=dp[a][0][X][Y][Z];
            }
        }
        
        ll ans=0;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<3;j++){
                ll copy=grundy;
                
                if(A[i]-att[j]<=0){
                    copy^=dp[A[i]][0][X][Y][Z];
                }else{
                    if(A[i]<=200){
                        copy^=dp[A[i]][0][X][Y][Z];
                    }else{
                        ll a=A[i];
                        a-=(A[i]-200)/roop[0][X][Y][Z]*roop[0][X][Y][Z];
                        copy^=dp[a][0][X][Y][Z];
                    }
                    
                    if(A[i]-att[j]<=200){
                        copy^=dp[A[i]-att[j]][j][X][Y][Z];
                    }else{
                        ll a=A[i]-att[j];
                        a-=(A[i]-att[j]-200)/roop[j][X][Y][Z]*roop[j][X][Y][Z];
                        copy^=dp[a][j][X][Y][Z];
                    }
                }
                
                if(copy==0) ans++;
            }
        }
        
        cout<<ans<<"\n";
    }
}