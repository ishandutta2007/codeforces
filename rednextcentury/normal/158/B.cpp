# include <algorithm>
# include <iostream>
using namespace std;
int a[1000000];
int b[5];
int main ()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    int ans=0;
    ans+=b[4];
    b[4]=0;
    int h=min(b[1],b[3]);
    ans+=h;
    b[1]-=h,b[3]-=h;
    ans+=b[3];
    b[3]=0;
    h=min(b[1]/2,b[2]);
    ans+=h;
    b[1]-=2*h,b[2]-=h;
    if (b[2]>0 && b[1]>0) ans++,b[2]--,b[1]--;
    ans+=b[2]/2+(b[2]%2>0);
    ans+=(b[1]/4)+(b[1]%4>0);
    cout<<ans<<endl;
}