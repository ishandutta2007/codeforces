#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    string S;cin>>S;
    int cnt=0,mini=0;
    for(int i=0;i<N;i++){
        if(S[i]=='(') cnt++;
        else cnt--;
        mini=min(mini,cnt);
    }
    if(cnt==0&&mini>=-1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}