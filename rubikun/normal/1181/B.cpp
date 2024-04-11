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
    
    string ans;
    for(int i=0;i<300000;i++) ans+='9';
    
    for(int i=int(S.size()/2);i>0;i--){
        if(S[i]!='0'){
            string A=S.substr(0,i),B=S.substr(i);
            vector<int> sum(200000);
            for(int j=0;j<A.size();j++){
                sum[200000-int(A.size())+j]+=A[j]-'0';
            }
            for(int j=0;j<B.size();j++){
                sum[200000-int(B.size())+j]+=B[j]-'0';
            }
            
            for(int j=199999;j>0;j--){
                if(sum[j]>=10){
                    sum[j-1]+=sum[j]/10;
                    sum[j]%=10;
                }
            }
            
            string C;
            for(int j=0;j<200000;j++){
                C+=char('0'+sum[j]);
            }
            int now=0;
            
            while(now<C.size()&&C[now]=='0'){
                now++;
            }
            
            C=C.substr(now);
            
            if(C.size()<ans.size()) ans=C;
            else if(C.size()==ans.size()){
                if(C<ans) ans=C;
            }
            
            break;
        }
    }
    
    for(int i=int(S.size()/2)+1;i<S.size();i++){
        if(S[i]!='0'){
            string A=S.substr(0,i),B=S.substr(i);
            vector<int> sum(200000);
            for(int j=0;j<A.size();j++){
                sum[200000-int(A.size())+j]+=A[j]-'0';
            }
            for(int j=0;j<B.size();j++){
                sum[200000-int(B.size())+j]+=B[j]-'0';
            }
            
            for(int j=199999;j>0;j--){
                if(sum[j]>=10){
                    sum[j-1]+=sum[j]/10;
                    sum[j]%=10;
                }
            }
            
            string C;
            for(int j=0;j<200000;j++){
                C+=char('0'+sum[j]);
            }
            int now=0;
            
            while(now<C.size()&&C[now]=='0'){
                now++;
            }
            
            C=C.substr(now);
            
            if(C.size()<ans.size()) ans=C;
            else if(C.size()==ans.size()){
                if(C<ans) ans=C;
            }
            
            break;
        }
    }
    
    cout<<ans<<endl;
}