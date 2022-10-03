#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    string S;cin>>S;
    int cnt=0;
    for(int i=0;i<N;i++){
        if(S[i]=='(') cnt++;
        else cnt--;
    }
    
    if(cnt!=0){
        cout<<-1<<endl;
        return 0;
    }
    
    int ans=0;
    
    cnt=0;
    for(int i=0;i<N;i++){
        if(S[i]=='(') cnt++;
        else cnt--;
        
        if(cnt<0){
            int now=i+1;
            while(now<N&&cnt<0){
                if(S[now]=='(') cnt++;
                else cnt--;
                
                now++;
            }
            ans+=now-i;
            i=now-1;
        }
    }
    
    cout<<ans<<endl;
}