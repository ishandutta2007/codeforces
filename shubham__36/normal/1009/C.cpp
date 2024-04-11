#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    long long int n,m,z,k,zs=0;
    long double ans=0;
    cin >> n >> m;
    while(m--){
        cin >> z >> k;
        zs+=z;
        if(k==0) ans+=0;
        else if(k<0){
            if(n%2==0) {
                
                ans+=(1.0*k*(n/2)*(n/2));}
            else ans+=(1.0*k*(n/2)*((n/2)+1));
        }
        else{
            ans+=(1.0*k*(n*(n-1))/2);
        }
    }
    ans/=n;
    ans+=zs;
    cout << fixed << setprecision(50) << ans << endl;
 return 0;
}