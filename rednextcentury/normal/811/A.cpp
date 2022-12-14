#include <bits/stdc++.h>

using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int cur=1;
    while(1)
    {
        if (cur%2 && a<cur)
        {
            cout<<"Vladik"<<endl;
            return 0;
        }
        else if (cur%2==0 && b<cur)
        {
            cout<<"Valera"<<endl;
            return 0;
        }
        if (cur%2)a-=cur;
        else b-=cur;
        cur++;
    }
}