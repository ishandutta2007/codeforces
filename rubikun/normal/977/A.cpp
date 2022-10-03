#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2001,INF=1<<30;

int main(){

    int N,K;cin>>N>>K;
    for(int i=0;i<K;i++){
        if(N%10==0) N/=10;
        else N--;
    }
    cout<<N<<endl;
}