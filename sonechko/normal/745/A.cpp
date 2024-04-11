
#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 10;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a)*(a))
#define y1 khdifkne
#define ll long long
map<string,bool> mt;
int main()
{
    string s;
    cin>>s;
    int ans=0;
    for (int k=1; k<=100; k++)
    {
        string t="";
        t+=s[s.size()-1];
        for (int i=0; i<s.size()-1; i++)
        t+=s[i];
        s=t;
        if (mt[s]==0) {mt[s]=1; ans++;}
    }
    cout<<ans<<endl;
}