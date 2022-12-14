# include <algorithm>
# include <iostream>
using namespace std;
int main ()
{
    long long now=0,max=0,a,b,n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
    cin>>a>>b;
    now-=a;
    now+=b;
    if (now>max)
        max=now;
    }
    cout<<max<<endl;
}