#include <iostream>

using namespace std;

int main()
{
    long long int n;
    cin >> n;
    long long int a[200001]={0},k,ans=0;
    for(long long int i=0;i<n;i++){
        cin >> k;
        a[k+100000]=1;
    }
    for(long long int i=0;i<200001;i++){
        if(a[i]!=0 && i!=100000) ans++;
    }
    cout << ans <<endl;
    return 0;
}