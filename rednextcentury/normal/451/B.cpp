#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>
#include <queue>
using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    a[n+1]=1000000001;
    if (n==1)
    {
        cout<<"yes\n1 1\n";
    }
    else
    {
        bool p=1;
        int start=-1;
        int finish=-1;
        for (int i=1;i<=n;i++)
        {
            if (a[i]<a[i-1])
            {
                if (finish!=-1)
                    p=0;
                else
                {
                    if (start!=-1)
                        continue;
                    start=i-1;
                }
            }
            else
            {
                if (start==-1)
                    continue;
                if (finish!=-1)
                    continue;
                finish=i-1;
            }
        }
        if (start!=-1 && finish==-1)
            finish=n;
        if (p==0)
            cout<<"no"<<endl;
        else if (finish==-1 && start==-1)
            cout<<"yes\n1 1\n";
        else if (start!=-1 && finish!=-1)
        {
            if (a[start]<a[finish+1] && a[finish]>a[start-1])
            cout<<"yes\n"<<start<<" "<<finish<<endl;
            else
            cout<<"no\n";
        }

    }
}