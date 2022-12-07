#include <iostream>
#include <fstream>
using namespace std;
int N, X;
int main()
{
    cin>>N>>X;
    int Z = (1<<18);
    if(N==2&&X==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    if(N>=2)
    {
        for(int i=0; i<N-3; i++)
        {
            cout<<i<<" ";
            X = (X^i);
        }
        if(N>2)
        {
            for(int i=N-2;; i++)
            {
                if((X^i)!=0)
                {
                    cout<<i<<" ";
                    X = (X^i);
                    break;
                }
            }
        }
        cout<<Z<<" "<<(X^Z)<<endl;
    }
    if(N==1)
    {
        cout<<X<<endl;
    }
}