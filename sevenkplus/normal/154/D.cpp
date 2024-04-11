#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll x,y,a,b;
int main()
{
    cin>>x>>y>>a>>b;
    if(a<=y-x&&y-x<=b){cout<<"FIRST"<<endl<<y<<endl;return 0;}
    if(y>x&&a<0||y<x&&b>0){cout<<"DRAW"<<endl;return 0;}
    if(a==0||b==0){cout<<"DRAW"<<endl;return 0;}
    if(abs(y-x)%abs(a+b)==0){cout<<"SECOND"<<endl;return 0;}
    if(min(abs(a),abs(b))<=abs(y-x)%abs(a+b)&&abs(y-x)%abs(a+b)<=max(abs(a),abs(b)))
        {cout<<"FIRST"<<endl<<x+(x<y?(abs(y-x)%abs(a+b)):(-(abs(y-x)%abs(a+b))))<<endl;return 0;}
    cout<<"DRAW"<<endl;
    return 0;
}