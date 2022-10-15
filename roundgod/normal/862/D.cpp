#include <bits/stdc++.h>
 
using namespace std;
 
string s;
int no,zero,one;
int n;
 
int query(string x)
{
    cout << "? " << x << endl; cout.flush();
    int ans;
    cin >> ans;
    return n-ans;
}
 
 
int query(int st,int en)
{
    string x=s;
    int i;
    for(i=st;i<=en;i++)
        x[i]='0';
    return query(x);
}
 
void go0(int x,int y)
{
    if(x==y)
    {
        zero=x;
        return;
    }
    int mid=(x+y)/2;
    int ans=query(x,mid)-no;
    if(ans!=-(mid-x+1))
        go0(x,mid);
    else
        go0(mid+1,y);
}
 
void go1(int x,int y)
{
    if(x==y)
    {
        one=x;
        return;
    }
    int mid=(x+y)/2;
    int ans=query(x,mid)-no;
    if(ans!=(mid-x+1))
        go1(x,mid);
    else
        go1(mid+1,y);
}
void go(int x,int y)
{
    int mid=(x+y)/2;
    int ans=query(x,mid)-no;
    if(ans==-(mid-x+1))
    {
        one=x; go0(mid+1,y);
    }
    else if(ans==(mid-x+1))
    {
        zero=x; go1(mid+1,y);
    }
    else
    {
        go(x,mid);
    }
}
 
int main()
{
    cin >> n;
    s=string(n,'1');
    no=query(s);
    go(0,n-1);
    cout << "! " << zero+1 << " " << one+1 << endl; cout.flush();
    return 0;
}