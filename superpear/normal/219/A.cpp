#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>

#define maxlongint 2147483647;

using namespace std;

string s;
int k,flag,a[200];

int main()
{
    cin>>k;
    cin>>s;
    memset(a,0,sizeof(a));
    for (int i=0;i<s.size();i++) a[s[i]-96]++;
    flag=1;
    for (int i=1;i<=26;i++)
        if (a[i]%k!=0)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    for (int i=1;i<=k;i++)
    {
        for (int j=1;j<=26;j++)
            for (int c=1;c<=a[j]/k;c++) printf("%c",j+96);
    }
    cout<<endl;
    return 0;
}