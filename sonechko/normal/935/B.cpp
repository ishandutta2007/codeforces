#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int type=0;
    int ans=-1;
    int pos1=0,pos2=0;
    int xx=0;
    for (int i=1; i<=n; i++)
    {
              char ch;
              cin>>ch;
              if (ch=='U') xx++; else xx--;
              if (xx>0&&type!=2) {ans++; type=2;} else
              if (xx<0&&type!=1) {ans++; type=1;}
    }
    cout<<ans<<endl;
}