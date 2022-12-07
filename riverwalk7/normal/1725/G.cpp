#include <bits/stdc++.h>
using namespace std;
int N;
int main()
{
    cin>>N;
    if(N == 1)
    {
        cout<<3<<endl;
    }
    else
    {
        cout<<(N/3)*4 + 3 + N % 3<<endl;
    }
}