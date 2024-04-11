#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, v;
    cin>>n>>v;
    long long s = 0;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i)
        cin>>a[i], s+=a[i];
       for(int i = 0; i < n; ++i)
        cin>>b[i];
    double cur = v*1.0/s;
    for(int i = 0; i < n ;++i)
        if(cur > b[i]/1.0/a[i])
            cur = b[i]/1.0/a[i];
    cout<<cur*s;
    return 0;
}