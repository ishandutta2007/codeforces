#include <iostream>
#include <fstream>
using namespace std;
int a[100];
int frequency[101];
int N;
int counter;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        frequency[a[i]]++;
        if(frequency[a[i]]==1)
        {
            counter++;
        }
    }
    if(counter != 2)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=1; i<=100; i++)
    {
        for(int j=i+1; j<=100; j++)
        {
            if(frequency[i] == frequency[j] && frequency[i] > 0)
            {
                cout<<"YES"<<endl;
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}