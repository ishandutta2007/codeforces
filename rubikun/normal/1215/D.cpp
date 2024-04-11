#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=17,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    string S;cin>>S;
    int left=0,right=0,cnt=0;
    for(int i=0;i<N/2;i++){
        if(S[i]=='?') cnt++;
        else left+=S[i]-'0';
    }
    for(int i=N/2;i<N;i++){
        if(S[i]=='?') cnt--;
        else right+=S[i]-'0';
    }
    if(cnt==0){
        if(left==right) cout<<"Bicarp"<<endl;
        else cout<<"Monocarp"<<endl;
    }else if(cnt>0){
        if(right-left==cnt/2*9) cout<<"Bicarp"<<endl;
        else cout<<"Monocarp"<<endl;
    }else{
        if(left-right==abs(cnt)/2*9) cout<<"Bicarp"<<endl;
        else cout<<"Monocarp"<<endl;
    }
}