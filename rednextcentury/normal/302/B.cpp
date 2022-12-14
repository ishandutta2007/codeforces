# include <iostream>
# include <stdio.h>
# include <map>
# include <string>
# include <queue>
# include <cstdio>
# include <cstdlib>
# include <stack>
# include <cmath>
# include <iomanip>
# include <algorithm>
# include <set>
# include <vector>
using namespace std;
map<int,int> mp;
int main()
{
    int n,m;
    cin>>n>>m;
    int now1=0;
    for (int i=0;i<n;i++)
    {
        int c,t;
        cin>>c>>t;
        now1+=c*t;
        mp[now1]=1;
    }
    map<int,int>::iterator it=mp.begin();
    int now=0;
    for (int i=0;i<m;i++)
    {
        int v;
        cin>>v;
        while(v>it->first)
        {
            it++;
            now++;
        }
        cout<<now+1<<endl;
    }
}