#include <iostream>
#include <fstream>
#define MAXN 1010
using namespace std;
int m;
int s[MAXN];
int main()
{
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>s[i];
        if(s[i]%s[0]!=0)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<2*m<<endl;
    for(int i=0; i<m-1; i++)
    {
        cout<<s[i]<<" "<<s[0]<<" ";
    }
    cout<<s[m-1]<<" "<<s[0]<<endl;
}