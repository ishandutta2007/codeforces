#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;string S;cin>>N>>S;
    int cnt=0;
    for(int i=0;i+1<N;i+=2){
        if(S[i]==S[i+1]){
            if(S[i]=='a') S[i]='b';
            else S[i]='a';
            cnt++;
        }
    }
    
    cout<<cnt<<endl;
    cout<<S<<endl;
}