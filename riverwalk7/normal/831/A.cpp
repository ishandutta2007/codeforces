#include <iostream>
using namespace std;
int N;
int a[1010];
int c;
int compareTo(int a, int b)
{
    if (a<b)
    {
        return -1;
    }
    if(a==b)
    {
        return 0;
    }
    if (a> b)
    {
        return 1;
    }
}
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<N-2; i++)
    {
        if(compareTo(a[i], a[i+1]) > compareTo(a[i+1], a[i+2]))
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}