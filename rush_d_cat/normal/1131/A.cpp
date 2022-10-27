#include <iostream>
using namespace std;
typedef long long LL;
int w1,h1,w2,h2;
int main(){
    cin>>w1>>h1>>w2>>h2;
    int ans=(w1+2)+(w2+2)+2*(h1-1)+2*(h2-1) + 2 + w1-w2+1 + 1;
    cout<<ans<<endl;

}