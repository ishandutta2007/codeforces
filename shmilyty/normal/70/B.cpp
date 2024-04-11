#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
char c[N];
int n,m=1,ans;
vector<int>v;
inline bool _end(char h){return (h=='?'||h=='.'||h=='!');}
int main()
{
    cin>>n;
    gets(c);
    gets(c);
    for(int i=0;i<strlen(c);i++)
    {
        if(!_end(c[i]))m++;
        else{
            v.push_back(m);
            if(m>n)
            {
                cout<<"Impossible\n";
                return 0;
            }
            m=0;
        }
    }
    for(int i=0;i<v.size();i++)
    {
        if(m+v[i]+1<=n&&m>0)m+=v[i]+1;
        else{
            m=0;
            ans++;
            m=v[i];
        }
    }
    cout<<ans;
}