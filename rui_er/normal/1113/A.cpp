//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int a, b;

int main()
{
    cin>>a>>b;
    if(b >= a - 1)
    {
        cout<<a-1<<endl;
        return 0;
    }
    cout<<b+(a-b+2)*(a-b-1)/2<<endl;
    return 0;
}