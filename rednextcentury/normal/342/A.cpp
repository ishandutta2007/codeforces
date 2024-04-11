#include <iostream>
# include <map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map <int,int> a;
    for (int i=0;i<n;i++)
    {
        int now;
        cin>>now;
        a[now]++;
    }
    if (a[1]+a[6]+a[2]+a[4]+a[3]==n && a[1]==n/3 && a[2]+a[3]==n/3 && a[2]>=a[4])
    {
        for (int i=0;i<n/3;i++)
        {
            
            if (a[4]>0 && a[2]>0)
            {
                cout<<1<<" "<<2<<" "<<4<<endl;
                a[4]--;
                a[2]--;
            }
            else if (a[6]>0 && a[2]>0)
            {
                cout<<1<<" "<<2<<" "<<6<<endl;
                a[6]--;
                a[2]--;
            }
            else
                cout<<1<<" "<<3<<" "<<6<<endl;
        }
    }
    else
        cout<<-1<<endl;
}