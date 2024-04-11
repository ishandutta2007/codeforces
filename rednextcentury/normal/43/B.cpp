
# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<cmath>
# include <vector>
# include <iomanip>
#define EPS 1e-9
using namespace std;
map<char,int> mp;
int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    int n=a.length();
    int m=b.length();
    for (int i=0;i<n;i++)
    {
        if (a[i]==' ') continue;
        mp[a[i]]++;
    }
    for (int i=0;i<m;i++)
    {
        if (b[i]==' ') continue;
        mp[b[i]]--;
        if (mp[b[i]]<0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}