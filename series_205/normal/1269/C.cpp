#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

int n,k;
string x,y;

int main(){
    cin>>n>>k>>x;
    cout<<n<<endl;
    y.resize(n);
    rep(i,n)y[i]=x[i%k];
    if(x<=y){
        cout<<y<<endl;
        return 0;
    }
    int num=k-1;
    while(x[num]=='9'){
        x[num]='0';
        num--;
    }
    x[num]++;
    rep(i,n)y[i]=x[i%k];
    cout<<y<<endl;
}