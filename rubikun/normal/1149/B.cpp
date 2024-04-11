#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=100000007,MAX=305,INF=1<<30;
int dp[MAX][MAX][MAX];
int nex[26][100015];
vector<int> when[26];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,Q;cin>>N>>Q;
    string S;cin>>S;
    for(int i=0;i<26;i++){
        for(int j=0;j<=100005;j++){
            nex[i][j]=INF;
        }
    }
    for(int i=0;i<S.size();i++){
        nex[S[i]-'a'][i]=i+1;
        //when[S[i]-'a'].emplace_back(i+1);
    }
    
    for(int i=0;i<26;i++){
        for(int j=N;j>=0;j--){
            nex[i][j]=min(nex[i][j],nex[i][j+1]);
        }
    }
    /*for(int i=0;i<26;i++){
        when[i].emplace_back(INF);
    }*/
    vector<string> T(3);
    for(int i=0;i<=260;i++){
        for(int j=0;j<=260;j++){
            for(int k=0;k<=260;k++){
                dp[i][j][k]=INF;
            }
        }
    }
    dp[0][0][0]=0;
    
    while(Q--){
        char wh,c;
        int num;cin>>wh>>num;
        num--;
        if(wh=='+'){
            cin>>c;
            T[num]+=c;
            int s1=0,s2=0,s3=0;
            if(num==0) s1=T[num].size();
            else if(num==1) s2=T[num].size();
            else if(num==2) s3=T[num].size();
            
            for(int i=s1;i<=T[0].size();i++){
                for(int j=s2;j<=T[1].size();j++){
                    for(int k=s3;k<=T[2].size();k++){
                        dp[i][j][k]=INF;
                    }
                }
            }
            
            if(num==0) s1--;
            else if(num==1) s2--;
            else if(num==2) s3--;
            
            //for(int turn=0;turn<6;turn++){
                for(int i=s1;i<=T[0].size();i++){
                    for(int j=s2;j<=T[1].size();j++){
                        for(int k=s3;k<=T[2].size();k++){
                            if(dp[i][j][k]==INF) continue;
                            if(i!=T[0].size()){
                                char to=T[0][i];
                                //auto it=upper_bound(all(when[to-'a']),dp[i][j][k]);
                                dp[i+1][j][k]=min(dp[i+1][j][k],nex[to-'a'][dp[i][j][k]]);
                            }
                            
                            if(j!=T[1].size()){
                                char to=T[1][j];
                                //auto it=upper_bound(all(when[to-'a']),dp[i][j][k]);
                                dp[i][j+1][k]=min(dp[i][j+1][k],nex[to-'a'][dp[i][j][k]]);
                            }
                            
                            if(k!=T[2].size()){
                                char to=T[2][k];
                                //auto it=upper_bound(all(when[to-'a']),dp[i][j][k]);
                                dp[i][j][k+1]=min(dp[i][j][k+1],nex[to-'a'][dp[i][j][k]]);
                            }
                        }
                    }
                }
            //}
            
        }else{
            T[num].erase(T[num].size()-1);
            int s1=0,s2=0,s3=0;
            if(num==0) s1=T[num].size()+1;
            else if(num==1) s2=T[num].size()+1;
            else if(num==2) s3=T[num].size()+1;
            
            for(int i=s1;i<=T[0].size()+1;i++){
                for(int j=s2;j<=T[1].size()+1;j++){
                    for(int k=s3;k<=T[2].size()+1;k++){
                        dp[i][j][k]=INF;
                    }
                }
            }
            
        }
        
        if(dp[T[0].size()][T[1].size()][T[2].size()]!=INF) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    
}