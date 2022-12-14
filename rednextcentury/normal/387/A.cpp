# include <iostream>
# include <stdio.h>
# include <map>
# include <algorithm>
# include <queue>
# include <stack>
using namespace std;
int main()
{
    int h1,m1,h2,m2;
    char x;
    cin>>h1>>x>>m1>>h2>>x>>m2;
    int time1=h1*3600+m1*60;
    int time2=h2*3600+m2*60;
    int ans;
    if (time1>time2)
        ans=time1-time2;
    else
        ans=24*3600+(time1-time2);
    if ((ans/3600)%24<10)
        cout<<0;
    cout<<(ans/3600)%24<<":";
    if ((ans%3600)/60<10)
        cout<<0;
    cout<<(ans%3600)/60<<endl;
}