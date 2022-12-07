#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string s;
int N, M;
int l, r;
char c1, c2;
int main()
{
    cin>>N>>M;
    cin>>s;
    for(int i=0; i<M; i++)
    {
        cin>>l>>r>>c1>>c2;
        for(int j=l-1; j<=(r-1); j++)
        {
            if(s[j]==c1)
            {
                s[j] = c2;
            }
        }
    }
    cout<<s<<endl;
}