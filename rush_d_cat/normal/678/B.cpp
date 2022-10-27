#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef __int64 ll;
bool isleap(int n)
{
    if(n%400==0) return true;
    if(n%4==0&&n%100!=0) return true;
    return false;
}
bool same(int a,int b)
{
    if(isleap(a)&&isleap(b)) return true;
    if(!isleap(a)&&!isleap(b))return true;
    return false;
}
int main()
{
    int n;cin>>n;
    int t=n,d=1;
    while(1)
    {
        if(t!=n&&d==1&&same(n,t)) break;
        if(isleap(t)) d = (d+366%7)%7;
        else d=(d+365%7)%7;
        t++;
    }
    cout<<t<<endl;
    return 0;
}