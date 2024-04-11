#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int rui(int a,int b){
    if(b==1) return a;
    else if(b==0) return 1;
    else if(b%2==0) return (rui(a,b/2)*rui(a,b/2));
    else return (rui(a,b-1)*a);
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,L,R;cin>>N>>L>>R;
    cout<<rui(2,L)+N-L-1<<" ";
    cout<<rui(2,R)-1+rui(2,R-1)*(N-R)<<endl;
}