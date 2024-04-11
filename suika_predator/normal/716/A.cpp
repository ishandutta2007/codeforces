#include<iostream>
using namespace std;
int n,c,cur,last,tot;
int main()
{
    cin>>n>>c;
    while(n--)
    {
        last=cur;
        cin>>cur;
        if(cur-last>c)tot=0;
        tot++;
    }
    cout<<tot<<endl;
    return 0;
}