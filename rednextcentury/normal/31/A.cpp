# include <iostream>
# include <algorithm>
using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            for (int k=0;k<n;k++)
            {
                if (i==j || i==k || j==k) continue;
                if (a[i]==a[j]+a[k])
                {
                    cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<-1<<endl;
}