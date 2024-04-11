#include <iostream>
using namespace std;
int ans;
int main() {
    int w,h,k;
    cin>>w>>h>>k;
    for(int i=1;i<=k;i++){
        ans+=2*(h+w)-4;
        h-=4,w-=4;
    }
    cout<<ans<<endl;
}