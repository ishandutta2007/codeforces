# include <iostream>
# include <algorithm>
# include <map>
using namespace std;
int a[3];
int b[3];
int main()
{
    map <int,int> m;
    for (int i=0;i<3;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+3);
    int max=a[2];
    int mid=a[1];
    int min=a[0];
    if (min+mid<max || ((mid+min)-max)%2!=0)
        cout<<"Impossible"<<endl;
    else
    {
        int midtolow=((mid+min)-max)/2;
        int midtomax=mid-midtolow;
        int mintomax=min-midtolow;
        if (b[0]+b[1]==mid+max)
            cout<<midtomax<<" ";
        else if (b[0]+b[1]==min+max)
            cout<<mintomax<<" ";
        else if (b[0]+b[1]==min+mid)
            cout<<midtolow<<" ";
        if (b[1]+b[2]==max+min)
            cout<<mintomax<<" ";
        else if (b[1]+b[2]==min+mid)
            cout<<midtolow<<" ";
        else
            cout<<midtomax<<" ";
        if (b[2]+b[0]==max+min)
            cout<<mintomax;
        else if (b[2]+b[0]==mid+max)
            cout<<midtomax;
        else
            cout<<midtolow;
        cout<<endl;
    }
}