#include <iostream>
#include <algorithm>
#include <cmath>
//#include <vector>
//#include <string>
//#include <iomanip>

using namespace std;

int main()
{
    long long int n,ans=0,total=0,prev,b=0,temp=0;
    cin >> n;
    long long int a[n];
    for(long long int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(long long int i=0;i<n;i++){
        if(a[i]==temp) ans++;
        else {
                b=max(ans,b);
                temp=a[i];
                ans=1;
        }
    }
    b=max(ans,b);
    for(long long int i=0;i<n;i++){
        if(a[(i+b)%n]>a[i]) total++;;
    }
    cout << total;
    return 0;
}