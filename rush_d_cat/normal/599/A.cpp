#include <iostream>
using namespace std;
int d1,d2,d3;
int main(){
    cin>>d1>>d2>>d3;
    int ans=min(d1+d2+d3,2*(d1+d2));
    ans=min(ans,2*(d1+d3));
    ans=min(ans,2*(d2+d3));
    cout<<ans<<endl;
}