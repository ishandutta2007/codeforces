#include <iostream>
#define MAXN 26
using namespace std;
string s;
int k;
bool used[MAXN];
int c, b;
int main()
{
    cin>>s>>k;
    for(int i=0; i<s.length(); i++)
    {
        b = s[i]-'a';
        if(!used[b])
        {
            used[b] = true;
            c++;
        }
    }
    if(s.length() < k)
    {
        cout<<"impossible"<<endl;
    }
    else
    {
        cout<<max(0, k-c)<<endl;
    }
}