#include <bits/stdc++.h>

using namespace std;
void print(char x,int n)
{
    for (int i=0;i<n;i++) cout<<x;
}
int main()
{
    int a1,a2,a3,a4;
    cin>>a1>>a2>>a3>>a4;
    if (a1+a2-1 < a3+a4 || abs(a3-a4)>1 || a2<a4 || a1<a3 || a3>a2 || a4-1>a1)
    {
        cout<<-1<<endl;
        return 0;
    }
    if (a3==a4)
    {
        if (a1==a4)
        {
            print('7',1);
            for (int i=0;i<a3;i++)
                print('4',1),print('7',1);
            print('7',a2-a3-1);
            return 0;
        }
        print('4',a1-a3);
        for (int i=0;i<a3-1;i++)
            print('7',1),print('4',1);
        print('7',a2-a3+1);
        print('4',1);
        return 0;
    }
    else if (a3>a4)
    {
        print('4',a1-a3+1);
        for (int i=0;i<a3-1;i++)
            print('7',1),print('4',1);
        print('7',a2-a3+1);
        return 0;
    }
    else
    {
        if (a1==a3)
        {
            cout<<-1<<endl;
            return 0;
        }
        print('7',1);
        print('4',a1-a3);
        for (int i=0;i<a3-1;i++)
            print('7',1),print('4',1);
        print('7',a2-a3);
        print('4',1);
    }
}