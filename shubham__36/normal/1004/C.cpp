#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    long long int n;
    cin >> n;
    long long int a[n],b[100000]={0},c[100000]={0},mcount=0,ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[a[i]-1]++;
    }
    for(int i=0;i<100000;i++){
        if(b[i]!=0) mcount++;
    }
    for(int i=0;i<n;i++){
        if(c[a[i]-1]!=0){
            b[a[i]-1]--;
        if(b[a[i]-1]==0) mcount--;
                continue;}
        c[a[i]-1]=1;

        b[a[i]-1]--;
        if(b[a[i]-1]==0) mcount--;
        ans+=mcount;
    }
    cout << ans << endl;
    return 0;
}