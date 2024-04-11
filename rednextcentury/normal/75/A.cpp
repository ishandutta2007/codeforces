# include <iostream>
# include <string>
# include <cstdlib>
#define EPS 1e-9
using namespace std;
int RZ(int x)
{
    int y=0;
    int cur[20];
    while(x)
    {
        if (x%10==0)
            x/=10;
        else
        {
            cur[y++]=x%10;
            x/=10;
        }
    }
    int ret=0;
    for (int i=y-1;i>=0;i--)
        ret=ret*10+cur[i];
    return ret;
}
int main()
{
    int a,b;
    cin>>a>>b;
    if (RZ(a)+RZ(b)==RZ(a+b))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}