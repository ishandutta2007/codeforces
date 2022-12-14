# include <iostream>
using namespace std;
bool a[10000];
int main()
{
    int n,p;
    cin>>p>>n;
    bool k=1;
    for (int i=0;i<n;i++)
    {
        int h;
        cin>>h;
        h=h%p;
        if (a[h] && k)
        {
        k=0;
            cout<<i+1<<endl;
            }
        else if (a[h]==0)
            a[h]=1;
    }
    if (k)
    cout<<-1<<endl;
}