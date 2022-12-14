# include <iostream>
# include <map>
# include <string>
# include <algorithm>
using namespace std;
map<int,int> m;
int a[100000];
int b[100000];
int main()
{
    int n;
    cin>>n;
    int f=-1;
    for (int d=0;d<n;d++)
    {
        cin>>a[d];
        if (a[d]>f)
            f=a[d];
        m[a[d]]++;
    }
    int len=m.size();
    int loc=0;
    for (int i=0;i<=5000;i++)
    {
        if (m[i]>0)
        {
            b[loc++]=i;
            m[i]--;
        }
    }
    for (int i=f-1;i>=0;i--)
    {
        if (m[i]>0)
        {
            b[loc++]=i;
            m[i]--;
        }
    }
    cout<<loc<<endl;
    for (int i=0;i<loc;i++)
        cout<<b[i]<<" ";
    cout<<endl;
}