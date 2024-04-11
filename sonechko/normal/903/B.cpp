#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 1e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int h1,a1,c1;
    int h2,a2;
    cin>>h1>>a1>>c1>>h2>>a2;
    vector<string> v;
    for (int i=1; i<=1000000; i++)
    {
        if (h2<=a1) {v.pb("STRIKE"); break;}
        if (h1>a2) {v.pb("STRIKE"); h2-=a1; h1-=a2;} else
        {
            v.pb("HEAL");
            h1+=c1;
            h1-=a2;
        }
    }
    cout<<v.size()<<endl;
    for (int i=0; i<v.size(); i++)
        cout<<v[i]<<endl;
}