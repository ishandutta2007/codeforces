#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int gcd (int a, int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
int f(int a)
{
    int cnt=0;
    for (int i=1;i*i<=a;i++)
    {
        if (a%i==0)
        {
            if (a/i!=i) cnt++;
            cnt++;
        }
    }
    return cnt;
}


int main()
{
    vector <char> a1,a2;
    int n1=0,n2=0;
    char c=getchar();
    while (c!='\n')
    {
        a1.push_back(c);
        c=getchar();
        n1++;
    }
    c=getchar();
    while (c!='\n')
    {
        a2.push_back(c);
        c=getchar();
        n2++;
    }
    int per1,per2;

    int y=1;
    for (int i=0;i<n1;i++)
    {
        while (y+i<n1&&a1[i]!=a1[i+y]) y++;
    }
    bool ok=true;
    for (int i=0;i<n1-y;i++)
    {
        if (a1[i]!=a1[i+y]) ok=false;
    }
    if (ok) per1=y; else per1=n1;

    y=1;
    for (int i=0;i<n2;i++)
    {
        while (y+i<n2&&a2[i]!=a2[i+y]) y++;
    }
    ok=true;
    for (int i=0;i<n2-y;i++)
    {
        if (a2[i]!=a2[i+y]) ok=false;
    }
    if (ok) per2=y; else per2=n2;
    if (n1%per1!=0) per1=n1;
    if (n2%per2!=0) per2=n2;

    if (per1!=per2)
    {
        cout << "0";
        return 0;
    }
    ok=true;
    for (int i=0;i<per1;i++)
    {
        if (a1[i]!=a2[i]) ok=false;
    }
    if (!ok)
    {
        cout << "0";
        return 0;
    }
    cout << f(gcd(n1/per1,n2/per2));

    return 0;
}