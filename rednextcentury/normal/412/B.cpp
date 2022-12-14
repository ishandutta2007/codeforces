# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <iomanip>
# include <string>
# include <ios>
# include <vector>
# include <algorithm>
using namespace std;
int a[100000];
bool comp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,comp);
    cout<<a[k-1]<<endl;
}