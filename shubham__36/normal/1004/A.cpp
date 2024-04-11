#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int a[n],k,ans=2,temp;
    cin >> k;
    cin >> a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        temp=a[i]-a[i-1];
        if(temp == 2*k){
            ans++;
        }
        else if(temp > 2*k){
            ans+=2;
        }
    }
    cout << ans << endl;
    return 0;
}