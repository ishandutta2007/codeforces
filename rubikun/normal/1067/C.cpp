#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    cout<<"0 0"<<endl;
    N--;
    for(int i=1;i<=N/4;i++){
        cout<<i<<" "<<0<<"\n";
        cout<<0<<" "<<i<<"\n";
        cout<<-i<<" "<<0<<"\n";
        cout<<0<<" "<<-i<<"\n";
    }
    
    if(N%4){
        cout<<N/4+1<<" "<<0<<endl;
        N--;
    }
    if(N%4){
        cout<<0<<" "<<N/4+1<<endl;
        N--;
    }
    if(N%4){
        cout<<-(N/4+1)<<" "<<0<<endl;
        N--;
    }
}