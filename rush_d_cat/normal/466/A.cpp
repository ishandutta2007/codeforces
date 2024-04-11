#include <iostream>
using namespace std;
int n,m,a,b;

int main() {
    cin>>n>>m>>a>>b;
    int res=1e9;
    for(int i=0;;i++){
        res=min(res,i*b + max(n-i*m,0)*a);
        if(i*m>=n) break;
    }
    cout<<res<<endl;
}