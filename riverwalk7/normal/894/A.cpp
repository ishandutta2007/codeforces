#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string s;
int ans;
int main()
{
    cin>>s;
    int N = s.length();
    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            for(int k=j+1; k<N; k++)
            {
                if(s[i]=='Q'&&s[j]=='A'&&s[k]=='Q')
                {
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}