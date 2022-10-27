#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N=200000+10;
int a,b,c;
int main(){
    cin>>a>>b>>c;
    int ans=0;
    int now=a-1;
    for(int i=1;i<b+c;i++){
        if(i<=b && i<=c) {
            ans += (++now);
        } else if(i>max(b,c)) {
            ans += (--now);
        } else {
            ans += now;
        }
    }
    cout << ans << endl;
}