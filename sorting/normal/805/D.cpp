#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000007

vector<int> v;

int main ()
{
    string s;
    long long res=0,i,l,l2;

    cin>>s;

    l=s.size();
    l2=l;

    for(i=0;i<l;i++)
    {
        if(s[i]=='a')
        {
            v.push_back(i);
        }
    }

    for(i=v.size()-1;i>=0;i--)
    {
        res+=res+l-v.size()+i-v[i];
        res%=MOD;
    }

    cout<<res<<endl;

    return 0;
}