
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
    int h[3]={0};
    mp['A']=mp['B']=mp['C']=1;
    for (int i=0;i<3;i++)
    {
        char a,op,b;
        cin>>a>>op>>b;
        if (op=='<')
            mp[b]++,h[b-'A']++;
        else
            mp[a]++,h[a-'A']++;
    }
    sort(h,h+3);
    if (h[0]!=0 || h[1]!=1 || h[2]!=2)
        cout<<"Impossible"<<endl;
    else
    {
        for (int i=1;i<=3;i++)
        {
            map<char,int>::iterator it=mp.begin();
            while(it!=mp.end())
            {
                if (it->second==i)
                {
                    cout<<it->first;
                    break;
                }
                it++;
            }
        }
    }
}