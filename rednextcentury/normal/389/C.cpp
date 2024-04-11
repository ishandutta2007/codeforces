# include <iostream>
# include <map>
# include <iomanip>
# include <queue>
# include <algorithm>
using namespace std;
int a[1000];
int visited[1000];
void read(int a[],int n)
{
    for (int i=0;i<n;i++)
        cin>>a[i];
}
void print(int a[],int n)
{
    cout<<a[0];
    for (int i=1;i<n;i++)
        cout<<" "<<a[i];
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    read(a,n);
    sort(a,a+n);
    int ans=0;
    for (int i=0;i<n;i++)
    {
        if (visited[i]==1)
            continue;
        visited[i]=1;
        int now=1;
        for (int x=i+1;x<n;x++)
        {
            if (visited[x]==0 && a[x]>=now)
            {
                visited[x]=1;
                now++;
            }
        }
        ans++;
    }
    cout<<ans<<endl;
}