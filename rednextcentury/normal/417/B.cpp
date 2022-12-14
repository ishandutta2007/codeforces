# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <iomanip>
# include <queue>
# include <ios>
# include <vector>
# include <algorithm>
using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    bool p=1;
    for (int i=0;i<n;i++)
    {
        int x,k;
        cin>>x>>k;
        if (x==a[k])
            a[k]++;
        else if (x>a[k])
            p=0;
    }
    if (p==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}