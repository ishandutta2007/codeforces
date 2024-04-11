#include<iostream>

//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

using namespace std;

int main ()
{
    long long n,k;

    cin>>n>>k;

    if(n==1)
    {
        cout<<"0"<<endl;
        return 0;
    }

    if(k>n)
    {
        if(2*n-1<k)
        {
            cout<<"0"<<endl;
            return 0;
        }

        cout<<(2*n-k+1)/2<<endl;
        return 0;
    }

    cout<<(k-1)/2<<endl;

    return 0;
}