#include <iostream>
using namespace std;
typedef long long LL;
LL n;
LL gcd(LL x,LL y){
    return y==0?x:gcd(y,x%y);
}
LL lcm(LL x,LL y){
    return x*y/gcd(x,y);
}

int main() {
    cin>>n;
    LL ans=0;


    for(int i=n;i>=max(n-100,1LL);i--)
        for(int j=n;j>=max(n-100,1LL);j--)
            for(int k=n;k>=max(n-100,1LL);k--)
                ans=max(ans,lcm(lcm(i,j),k));
    

    cout<<ans<<endl;
}