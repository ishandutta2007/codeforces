#include <iostream>
using namespace std;
int l,r,x,y;
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main(){
    cin>>l>>r>>x>>y;
    if(y%x) return !printf("0\n");
    int k=y/x;
    int ans=0;
    for(int i=1;i*i<=k;i++) {
        if(k%i==0){
            int a=k/i;
            int b=i;

            if(a*x<l || a*x>r) continue;
            if(b*x<l || b*x>r) continue;

            if(gcd(a,b)==1) {
                if(a==b) ans++;
                else ans+=2;
            }
        }
    }
    cout<<ans<<endl;
}