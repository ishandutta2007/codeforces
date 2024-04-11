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
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long

using namespace std;

int main()
{
    string s;
    cin>>s;
    for (int i=1;i<=10000;i++)
        for (int j=0;j<int(s.size()-2);j++)
            if ((s[j]=='W')&&(s[j+1]=='U')&&(s[j+2]=='B'))
                {s.erase(j,2);s[j]=' ';break;}
    while (s[0]==' ') s.erase(0,1);
    while (s[s.size()-1]==' ') s.erase(s.size()-1,1);
    for (int i=1;i<=10000;i++)
        for (int j=0;j<s.size()-1;j++)
        {
            if ((s[j]==' ')&&(s[j+1]==' '))
            {
                s.erase(j,1);break;
            }
        }
    cout<<s<<endl;
    return 0;
}