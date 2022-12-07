#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
int N;
stack<int> speeds;
int overtake;
int t, s;
int speed;
int ans;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>t;
        if(t==1)
        {
            cin>>s;
            speed = s;
        }
        if(t==2)
        {
            ans += overtake;
            overtake = 0;
        }
        if(t==3)
        {
            cin>>s;
            speeds.push(s);
        }
        if(t==4)
        {
            overtake = 0;
        }
        if(t==5)
        {
            while(!speeds.empty())
            {
                speeds.pop();
            }
        }
        if(t==6)
        {
            overtake++;
        }
        while(!speeds.empty()&&speed > speeds.top())
        {
            speeds.pop();
            ans++;
        }
    }
    cout<<ans<<endl;
}