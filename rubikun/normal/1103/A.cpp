#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=10005,INF=1<<29;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    int cnt0=0,cnt1=0;
    
    for(int i=0;i<S.size();i++){
        if(S[i]=='1'){
            cout<<cnt0%4+1<<" "<<1<<"\n";
            cnt0++;
        }else{
            cout<<cnt1%2*2+1<<" "<<4<<"\n";
            cnt1++;
        }
    }
}