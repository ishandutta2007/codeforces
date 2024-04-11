#include<bits/stdc++.h>
using namespace std;



#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back



const int N = 1e6 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int ps=0;
    for (int i=0; i<s.size(); i++)
        if (i%2==0&&s[i]=='+') ps++; else
        if (i%2==1&&s[i]=='-') ps++; else ps--;
    if (ps==0) cout<<"Yes"<<endl; else cout<<"No"<<endl;
}