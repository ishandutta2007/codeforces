#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<59;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<string> S(N);
    for(int i=0;i<N;i++) cin>>S[i];
    
    vector<int> left(500003),right(500003);
    int mid=0;
    
    for(int i=0;i<N;i++){
        int cnt=0;
        for(int j=0;j<S[i].size();j++){
            if(S[i][j]=='(') cnt++;
            else cnt--;
        }
        if(cnt>0){
            int now=0;
            for(int j=0;j<S[i].size();j++){
                if(S[i][j]=='(') now++;
                else now--;
                
                if(now<0) break;
            }
            if(now>=0) left[cnt]++;
        }else if(cnt==0){
            int now=0;
            for(int j=0;j<S[i].size();j++){
                if(S[i][j]=='(') now++;
                else now--;
                
                if(now<0) break;
            }
            if(now>=0) mid++;
        }else{
            int now=0;
            for(int j=0;j<S[i].size();j++){
                if(S[i][j]=='(') now++;
                else now--;
                
                if(now<cnt) break;
            }
            if(now>=cnt) right[abs(cnt)]++;
        }
    }
    
    int ans=mid/2;
    
    for(int i=1;i<=500000;i++) ans+=min(left[i],right[i]);
    
    cout<<ans<<endl;
}