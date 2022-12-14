# include <iostream>
# include <string>
# include <map>
# include <stdio.h>
# include <cmath>
# include <cstdio>
# include <queue>
# include <algorithm>
# include <stack>
# include <cstring>
# include <iomanip>
# include<cstdlib>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int one=0,two=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if (x==100)
            one++;
        else
            two++;
    }
    int give=one*100+two*200;
    give/=2;
    if (give%100!=0)
        cout<<"NO"<<endl;
    else if ((give/100)%2==0)
        cout<<"YES"<<endl;
    else
    {
        if (one>=2)
            cout<<"YES"<<endl;
        else

        cout<<"NO"<<endl;
    }
}