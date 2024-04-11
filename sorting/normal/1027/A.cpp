#include<iostream>
#include<cmath>

//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

#define endl "\n"

using namespace std;

int main ()
{
    int t,n,i;
    string s;

    cin>>t;

    for(t;t>0;t--)
    {
        cin>>n>>s;

        for(i=0;i<n/2;i++)
        {
            if((int)abs(s[i]-s[n-i-1])>2 || (int)abs(s[i]-s[n-i-1])==1)
            {
                break;
            }
        }

        if(i==n/2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}