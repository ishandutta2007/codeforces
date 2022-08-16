#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

bool gcd(long long int a,long long int b)
{
    if(a==1) return false;
    if(b%a==0) return true;
    else return gcd(b-(b/a)*a,a);
}

int main()
{
    long long int n,m,i=1,j=2,k;
    bool bo=false;
    cin >> n >> m;
    if(m<n-1){
        cout << "Impossible";
        return 0;
    }
    k=m;
    long long int a[m],b[m];
    while(m--){
        if(i==n) {
                bo=true;
        break;}
        while((j<=i || gcd(i,j)) && j!=n+1) j++;
        if(j==n+1){
            i++;
            j=i+1;
            m++;
            continue;
        }
        a[m]=i;
        b[m]=j;
        j++;
    }
    if(bo) cout << "Impossible";
    else {
        cout << "Possible" << endl;
        while(k--){
            cout << a[k] << " " << b[k] << endl;
        }
    }
    return 0;
}