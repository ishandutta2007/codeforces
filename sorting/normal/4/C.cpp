#include<iostream>
#include<map>

using namespace std;

map<long long,int> mp;

#define MOD 1000000007
#define BASE 257

string s;

long long make_hash()
{
    int hash=0;
    for(int i=0;i<s.size();i++)
        hash=(hash*BASE+s[i])%MOD;

    return hash;
}

int main ()
{
    long long n,hash,hash2,p,st;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>s;

        hash=make_hash();

        if(!mp[hash])
        {
            mp[hash]=1;
            cout<<"OK"<<endl;
        }
        else
        {
            cout<<s<<mp[hash]<<endl;
            mp[hash]++;
        }
    }

    return 0;
}