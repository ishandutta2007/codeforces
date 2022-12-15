#include<iostream>

using namespace std;

bool check(int h,int m)
{
    if(h%10==7 || m%10==7)return 1;
    return 0;
}

int main ()
{
    int x,h,m,i;

    cin>>x>>h>>m;

    for(i=0;true;i++)
    {
        if(check(h,m))
        {
            cout<<i<<endl;
            return 0;
        }

        m-=x;
        if(m<0)
        {
            m+=60;
            h--;
            if(h<0)h=23;
        }
    }

    return 0;
}