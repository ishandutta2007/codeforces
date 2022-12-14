#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int last=-1;
    for (int i=0;i*7<=n;i++)
    {
        if ((n-(7*i))%4==0)
            last=i;
    }
    if (last==-1)
        cout<<-1<<endl;
    else
    {
        int numsev=last;
        int numfour=(n-(last*7))/4;
        for (int i=0;i<numfour;i++)
        {
            cout<<4;
        }
        for (int i=0;i<numsev;i++)
            cout<<7;
        cout<<endl;
    }
}