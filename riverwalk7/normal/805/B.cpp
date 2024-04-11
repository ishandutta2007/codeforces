#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    int N;
    cin>>N;
    s = "";
    for(int i=0; i<N; i++)
    {
        if(i%4==1||i%4==0)
        {
            s += "a";
        }
        else
        {
            s += "b";
        }
    }
    cout<<s<<endl;
}