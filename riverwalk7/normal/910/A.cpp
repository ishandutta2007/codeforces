#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int N, D;
int cur;
string s;
int ans;
int main()
{
    cin>>N>>D;
    cin>>s;
    cur = 1;
    while(true)
    {
        for(int i=N; i>cur; i--)
        {
            if((i-cur) <= D && s[i-1]=='1')
            {
                cur = i;
                ++ans;
                break;
            }
            if(i==(cur+1))
            {
                cout<<-1<<endl;
                return 0;
            }
        }
        if(cur==N)
        {
            cout<<ans<<endl;
            return 0;
        }
    }
}