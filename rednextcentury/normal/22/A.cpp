# include <iostream>
# include <algorithm>
using namespace std;
int a[10000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int i=1;
    a[n]=-1000;
    while(a[i]==a[0])
        i++;
    if (i==n)
        cout<<"NO"<<endl;
    else cout<<a[i]<<endl;
}