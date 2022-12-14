# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <cmath>
# include <iomanip>
# include <queue>
# include <ios>
# include <vector>
# include <algorithm>
using namespace std;
long long c[1000000];
int main()
{
    long long n,a,b;
    cin>>n>>a>>b;
    for (int i=0;i<n;i++)
    {
        cin>>c[i];
        c[i]*=a;
        c[i]=(c[i]%b)/a;
    }
    for (int i=0;i<n;i++)
        cout<<c[i]<<" ";
    cout<<endl;
}