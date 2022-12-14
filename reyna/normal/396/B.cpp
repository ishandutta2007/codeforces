//In the name of God
#include <iostream>
using namespace std;
long long gcd(long long a,long long b){
    return b?gcd(b,a % b):a;
}
long long lcm(long long a,long long b){
    return (a * b)/lcm(max(a,b),min(a,b));
}
bool isP(int now){
    for(int i = 2; i * i <= now;i++)
        if(now % i == 0)
            return 0;
    return 1;
}
int main(){
    int tc;
    cin >> tc;
    for(int q = 0; q < tc;q++){
        long long makh=0,sor=0;
        int n;
        cin >> n;
        n++;
        int back = 0;
        int one = 0;
        int two = 0;
        for(int i = n-1;i ;i--){
            back++;
            if(isP(i)){
                one = i;
                break;
            }
        }
        for(int i = n;i;i++)
            if(isP(i)){
                two = i;
                break;
            }
        sor = one + (two - n);
        makh = (long long)one * two;
        if(makh % 2 == 1){
            sor*=2;
            makh*=2;
        }
        sor = makh/2 - sor;
        long long GCD = gcd(makh,sor);
        sor /= GCD;
        makh /= GCD;
        cout << sor << '/' << makh << endl;
    }
    return 0;
}