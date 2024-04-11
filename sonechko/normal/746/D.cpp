
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
int main()
{
    int n,m,l,r;
    cin>>n>>m>>l>>r;
    int vid=0,kol=0;
    string t="";
    for (int i=1; i<=n; i++)
    {
        if (kol==m)
        {
            if (vid==0&&r==0) {cout<<"NO"<<endl; return 0;} else
            if (vid==1&&l==0) {cout<<"NO"<<endl; return 0;} else
            if (vid==0) {vid=1; t+="B"; r--; kol=1; } else {vid=0; t+="G"; l--; kol=1;}
        } else
        if (l>r)
        {
            if (vid==0) kol++; else
                {
                    vid=0;
                    kol=1;
                }
            l--;
            t+="G";
        } else
        {
            if (vid==1) kol++; else
            {
                vid=1;
                kol=1;
            }
            r--;
            t+="B";
        }
    }
    cout<<t<<endl;
}