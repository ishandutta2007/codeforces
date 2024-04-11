#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());

    ll H,L;cin>>H>>L;
    cout<<setprecision(25)<<(L*L-H*H)/(2.0*H)<<endl;
}