#include <iostream>
#include <algorithm>
using namespace std;
int n,a[100000];
long long x,y;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        y+=a[i];
    }sort(a,a+n);
    for(int i=0;i<n/2;i++)x+=a[i];
    y-=x;
    cout<<x*x+y*y<<endl;
    return 0;
}