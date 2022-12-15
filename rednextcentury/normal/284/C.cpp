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
# include<ios>
using namespace std;
int a[1000000];
int b[1000000];
int main()
{
    int n;
    cin>>n;
    long double sum=0;
    int num=1;
    for (int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if (type==1)
        {
            int k,x;
            cin>>k>>x;
            sum+=k*x;
            b[k]+=x;
        }
        else if (type==2)
        {
            int k;
            cin>>k;
            a[++num]=k;
            sum+=k;
        }
        else if (type==3)
        {
            sum-=b[num]+a[num];
            b[num-1]+=b[num];
            b[num]=0;
            num--;
        }
        cout<<setprecision(7)<<fixed<<long double(sum)/long double(num)<<endl;
    }
}