# include <algorithm>
# include <iostream>
using namespace std;
int main ()
{
long long n,a,b,c,ans1,total=0;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        ans1=0;
        for (int x=0;x<3;x++)
        {
            cin>>a;
            if (a==1)
                ans1++;
        }
    
        if (ans1>=2)
            total++;
    }
    cout<<total<<endl;
}