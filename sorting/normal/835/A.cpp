#include<iostream>

using namespace std;

int main ()
{
    int s,t1,t2,p1,p2,res1,res2;

    cin>>s>>t1>>t2>>p1>>p2;

    res1=s*t1+2*p1;
    res2=s*t2+2*p2;

    if(res1<res2)cout<<"First"<<endl;
    else
    {
        if(res1==res2)cout<<"Friendship"<<endl;
        else cout<<"Second"<<endl;
    }

    return 0;
}