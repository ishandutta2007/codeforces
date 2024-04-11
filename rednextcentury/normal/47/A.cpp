# include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        if ((i*(i+1)/2) == n)
        {
            cout<<"YES"<<endl;
            return 0;
        }  
    }
    cout<<"NO"<<endl;
}