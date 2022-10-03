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
    if(N%2==1) cout<<":("<<endl;
    else if(S[0]==')'||S[N-1]=='(') cout<<":("<<endl;
    else{
        S[0]='(';
        S[N-1]=')';
        
        int left=0,right=0,hatena=0;
        
        for(int i=1;i<S.size()-1;i++){
            if(S[i]=='(') left++;
            else if(S[i]==')') right++;
            else hatena++;
        }
        
        if(left<=(N-2)/2&&right<=(N-2)/2){
            for(int i=1;i<S.size()-1;i++){
                if(S[i]=='?'&&left<(N-2)/2){
                    left++;
                    S[i]='(';
                }else if(S[i]=='?'){
                    S[i]=')';
                }
            }
            
            int sum=0;
            bool ok=true;
            
            for(int i=0;i<S.size()-1;i++){
                if(S[i]=='(') sum++;
                else sum--;
                if(sum<=0) ok=false;
            }
            
            if(sum==1&&ok) cout<<S<<endl;
            else cout<<":("<<endl;
        }else cout<<":("<<endl;
    }
}