#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n,ans=1,tans=1;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];}
        sort(a,a+n);
        int temp=a[0];
    for(int i=1;i<n;i++){
        if(a[i]==temp){
            tans++;
        }
        else{
            temp=a[i];
            ans=max(ans,tans);
            tans=1;
        }
    }
    ans=max(ans,tans);
    cout << ans;
    return 0;
}