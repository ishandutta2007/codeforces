#include <bits/stdc++.h>
using namespace std;
int num[1000001];
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        num[x]++;
    }
    for (int i=1;i<=100000;i++)
    {
        if (num[i]%2)
        {
            cout<<"Conan"<<endl;
            return 0;
        }
    }
    cout<<"Agasa"<<endl;
}