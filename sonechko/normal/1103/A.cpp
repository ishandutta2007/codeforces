#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int p1=0,p2=0;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='0')
        {
            if (p1==0)
            {
                cout<<"1 1"<<endl;
                p1=1;
            } else
            {
                cout<<"3 1"<<endl;
                p1=0;
            }
        } else
        {
            if (p2==0)
            {
                cout<<"4 3"<<endl;
                p2=1;
            } else
            {
                cout<<"4 1"<<endl;
                p2=0;
            }
        }
    }
}