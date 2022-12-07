#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
string p, h, t;
int T;
char a[100];
bool flag;
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>p>>h;
        sort(p.begin(), p.end());
        if(p.length() > h.length())
        {
            cout<<"NO"<<endl;
        }
        else
        {
            flag = false;
            for(int i=0; i<=h.length()-p.length(); i++)
            {
                t = h.substr(i, p.length());
                sort(t.begin(), t.end());
                if(t == p)
                {
                    cout<<"YES"<<endl;
                    flag = true;
                    break;
                }
            }
            if(!flag)
            {
                cout<<"NO"<<endl;
            }
        }
    }
}