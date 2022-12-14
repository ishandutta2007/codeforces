# include <iostream>
# include <map>
# include <iomanip>
# include <queue>
# include <string>
using namespace std;
int a[1000];
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
    int min=1000000;
    for (int i=0;i<n;i++)
        if (a[i]<min)
            min=a[i];
    for (int i=min;i>0;i--)
    {
        bool p=0;
        for (int x=0;x<n;x++)
        {
            if (a[x]%i!=0)
            {
                p=1;
                break;
            }
        }
        if (p==0)
        {
            cout<<i*n<<endl;
            return 0;
        }
    }   
}