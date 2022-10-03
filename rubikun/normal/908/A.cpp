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
    
    string S;cin>>S;
    string T="aeiou13579";
    int cnt=0;
    
    for(int i=0;i<S.size();i++){
        for(int j=0;j<T.size();j++){
            if(S[i]==T[j]) cnt++;
        }
    }
    
    cout<<cnt<<endl;
}