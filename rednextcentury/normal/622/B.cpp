#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h,m;
    int a;
    scanf("%d:%d",&h,&m);
    scanf("%d",&a);
    int tim=h*60+m;
    tim+=a;
    h=(tim/60)%24;
    m=tim%60;
    if (h<10)
        cout<<"0";
    cout<<h<<":";

    if (m<10)
        cout<<"0";
    cout<<m<<endl;
}