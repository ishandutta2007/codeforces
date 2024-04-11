#include <iostream>
#define int long long int
using namespace std;
bool coprime (int a, int b) {
    int r, i;
    while(b!=0){
        r = a % b;
        a = b;
        b = r;
    }
    return a==1;
}
signed main() {
    int x,y;
    cin>>x>>y;
    for(int i=x;i<=y;i++){
        for(int j=i+1;j<=y;j++){
            for(int k=j+1;k<=y;k++){
                if(coprime(i,j) && coprime(j,k) && !coprime(i,k)){
                    cout<<i<<" "<<j<<" "<<k;
                    return 0;
                }
            }
        }
    }
    cout<<"-1";
    return 0;
}