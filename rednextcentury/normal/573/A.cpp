# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<cmath>
# include <vector>
# include <iomanip>
#define EPS 1e-9
using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        while(x%2==0)
            x/=2;
        while(x%3==0)
            x/=3;
        a[i]=x;
    }
    for (int i=1;i<n;i++)
    {
        if (a[i]!=a[i-1])
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}