#include <iostream>

using namespace std;

int N, M;


void print(int x)
{
    cout<<".";
    for(int i=2; i<=x/2+1; i++)
    {
        cout<<"#";
    }
    for(int i=x/2+2; i<=N/2; i++)
    {
        cout<<".";
    }
    if(x%2) cout<<"#";
    else    cout<<".";
    for(int i=x/2+2; i<=N/2; i++)
    {
        cout<<".";
    }
    for(int i=2; i<=x/2+1; i++)
    {
        cout<<"#";
    }
    cout<<"."<<endl;
}

int main()
{
    cin>>N>>M;
    cout<<"YES"<<endl;
    print(0);
    print(min(M, N-2));
    print(max(0, M-N+2));
    print(0);
    return 0;
}