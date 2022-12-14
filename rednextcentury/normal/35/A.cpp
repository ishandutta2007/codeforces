# include <iostream>
# include <stdio.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int id;
    cin>>id;
    for (int i=0;i<3;i++)
    {
        int a,b;
        cin>>a>>b;
        if (a==id)
            id=b;
        else if (b==id)
            id=a;
    }
    cout<<id<<endl;
}