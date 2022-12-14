# include <iostream>
using namespace std;
int a[10000000];
int main()
{
    int n;
    cin>>n;
    int ans=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (i>0 && a[i]!=a[i-1])
            ans++;
    }
    cout<<++ans<<endl;
}