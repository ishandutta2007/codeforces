#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=200005,INF=1<<30;
ll dp[1<<14][14][1<<8];
int gyaku[1<<6];
int gyaku2[1<<14];
bool fri[14][14];
ll ans[1<<14];
string S[14];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    
    for(int i=0;i<N;i++){
        cin>>S[i];
        for(int j=0;j<N;j++){
            if(S[i][j]=='1') fri[i][j]=1;
        }
    }
    
    int x=max(1<<7,1<<((N+1)/2-1));
    
    for(int bit=0;bit<(1<<N);bit++){
        int c=-1;
        for(int i=0;i<N;i++){
            if(bit&(1<<i)) c++;
            
            if(c>=6) break;
        }
        //int c=__builtin_popcount(bit)-1;
        if(c>=6) continue;
        
        for(int i=0;i<N;i++){
            if(bit&&!(bit&(1<<i))) continue;
            for(int to=0;to<N;to++){
                if(bit&(1<<to)) continue;
                
                for(int state=0;state<x;state++){
                    if(bit==0){
                        dp[1<<to][to][0]=1;
                    }else if(fri[i][to]){
                        dp[bit|(1<<to)][to][state|(1<<c)]+=dp[bit][i][state];
                        
                        //cout<<(bit|(1<<to))<<" "<<to<<" "<<(state|(1<<c))<<" "<<dp[bit|(1<<to)][to][state|(1<<c)]<<endl;
                    }else{
                        dp[bit|(1<<to)][to][state]+=dp[bit][i][state];
                    }
                }
            }
        }
    }
    
    if(N<=7){
        for(int j=0;j<N;j++){
            for(int state=0;state<(1<<(N-1));state++){
                ans[state]+=dp[(1<<N)-1][j][state];
            }
        }
        
        for(int state=0;state<(1<<(N-1));state++){
            cout<<ans[state]<<" ";
        }
        cout<<endl;
        
        return 0;
    }
    
    for(int state=0;state<(1<<(((N+1)>>1)-1));state++){
        for(int i=0;i<((N+1)>>1)-1;i++){
            if(state&(1<<i)) gyaku[state]|=1<<(N-2-i);
        }
    }
    
    for(int bit=0;bit<(1<<(N-1));bit++){
        for(int i=0;i<N-1;i++){
            if(bit&(1<<i)) gyaku2[bit]|=1<<(N-2-i);
        }
    }
    
    for(int bit=(1<<(((N+1)>>1)-1))+1;bit<(1<<N);bit+=2){
        //if((bit&1)==0) continue;
        if(__builtin_popcount(bit)!=((N+1)>>1)) continue;
        
        for(int i=0;i<N;i++){
            if(!(bit&(1<<i))) continue;
            
            for(int j=0;j<N;j++){
                if(bit&(1<<j)) continue;
                
                for(int state=0;state<(1<<(((N+1)>>1)-1));state++){
                    for(int tostate=0;tostate<(1<<(N-((N+1)>>1)-1));tostate++){
                        
                        if(fri[i][j]){
                            ans[(state|(1<<(((N+1)>>1)-1)))|gyaku[tostate]]+=dp[bit][i][state]*dp[(1<<N)-bit-1][j][tostate];
                            ans[gyaku2[(state|(1<<(((N+1)>>1)-1)))|gyaku[tostate]]]+=dp[bit][i][state]*dp[(1<<N)-bit-1][j][tostate];
                        }
                        else{
                            ans[state|gyaku[tostate]]+=dp[bit][i][state]*dp[(1<<N)-bit-1][j][tostate];
                            ans[gyaku2[state|gyaku[tostate]]]+=dp[bit][i][state]*dp[(1<<N)-bit-1][j][tostate];
                        }
                    }
                }
            }
        }
    }
    
    for(int state=0;state<(1<<(N-1));state++){
        cout<<ans[state]<<" ";
    }
    //cout<<"\n";
    
}