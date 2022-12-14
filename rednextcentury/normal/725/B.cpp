#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    char x;
    cin>>n>>x;
    if (n%2)
    {
        long long num=(n/4);
        num++;

        num=num*2-1;
        num=(num-1)*6;
        if ((n/2)%2==0)
            num+=n-1;
        else num+=n-3;
        if (x=='f')num++;
        else if (x=='e')num+=2;
        else if (x=='d')num+=3;
        else if (x=='a')num+=4;
        else if (x=='b')num+=5;
        else num+=6;
        cout<<num<<endl;
    }
    else
    {
        long long num=((n-1)/4);
        num++;

        num=num*2;
        num=(num-1)*6;
        if (((n-1)/2)%2==0)
            num+=n-1;
        else num+=n-3;
        if (x=='f')num++;
        else if (x=='e')num+=2;
        else if (x=='d')num+=3;
        else if (x=='a')num+=4;
        else if (x=='b')num+=5;
        else num+=6;
        cout<<num<<endl;
    }
}