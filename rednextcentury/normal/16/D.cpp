
# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<stdio.h>
# include <vector>
#define EPS 1e-9
using namespace std;
int main()
{
    int n;
    cin>>n;
    int last=-1;
    int days=1;
    int num=0;
    for (int i=0;i<n;i++)
    {
        char x='p';

        while(x!='[')
            cin>>x;
        int h;
        cin>>h;
        cin>>x;
        int m;
        cin>>m;
        string g;
        cin>>g;
        if ( h==12)
            h=0;
        if (g[0]=='p')
            h+=12;
        int cur=h*60+m;
        if (cur!=last)num=1;
        if (cur<last)
            days++;
        if (cur==last)
            num++;
        if (num>10)
            num-=10,days++;
        last=cur;
    }
    cout<<days<<endl;
}