#include <iostream>

using namespace std;

void swapp (bool *p0, int num)
{
    if (num==1)
    {
        *p0=*(p0+2);
        *(p0+2)=*(p0+3);
        *(p0+3)=*p0;
    }
    if (num==2)
    {
        *p0=*(p0+1);
        *(p0+1)=*(p0+3);
        *(p0+3)=*p0;
    }
    if (num==3)
    {
        *p0=*(p0+2);
        *(p0+2)=*(p0+1);
        *(p0+1)=*p0;
    }
}

int main()
{
    bool p[4]; p[1]=true; p[2]=true; p[3]=false; bool *pp=&p[0];
    int n; int a[100];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    int k=0;
    while (k<n)
    {
        if (p[a[k]]==false)
        {
            cout << "NO";
            return 0;
        }
        swapp (pp, a[k]);
        k++;
    }
    cout << "YES";
    return 0;
}