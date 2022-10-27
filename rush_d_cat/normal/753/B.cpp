#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec, res;
int x, y, a[5];
int main()
{
    for(int i=0;i<=9;i++)
    {
        printf("%d%d%d%d\n",i,i,i,i);
        fflush(stdout);
        cin>>x>>y;
        int k = x+y;
        while(k--) vec.push_back(i);
    }
    for(int i=0;i<=9999;i++)
    {
        int t = i;
        a[0] = t%10;t/=10;
        a[1] = t%10;t/=10;
        a[2] = t%10;t/=10;
        a[3] = t%10;t/=10;
        sort(a,a+4);
        if(a[0] == vec[0]&&a[1] == vec[1]&&a[2] == vec[2]&&a[3] == vec[3])
        {
            res.push_back(i);
        }
    }
    for(int i=0;i<res.size();i++)
    {
        if(res[i]<10) printf("000");
        if(res[i]<100) printf("00");
        if(res[i]<1000) printf("0");
        printf("%d\n", res[i]);
        fflush(stdout);
        cin >> x >> y;
        if(x==4)
        {
            break;
        }
    }
}