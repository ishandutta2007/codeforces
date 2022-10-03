#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=1<<19,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    int cnt1=0,cnt2=0;
    for(int i=0;i<N;i++){
        int a;cin>>a;
        if(a%2) cnt1++;
        else cnt2++;
    }
    cout<<min(cnt1,cnt2)<<endl;
}