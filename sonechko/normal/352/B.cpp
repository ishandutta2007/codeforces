#include<bits/stdc++.h>
using namespace std;
#define pb push_back


const int N = 1e5 + 11;
int use[N];
int d[N];
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for (int i=1; i<=n; i++)
        {
            int k;
            cin>>k;
            if (use[k]!=0)
            {
                if (d[k]==0) d[k]=i-use[k]; else
                if (d[k]!=i-use[k]) d[k]=-1;
            } else v.pb(k);
            use[k]=i;
        }
    vector<int> w;
    for (int i=0; i<v.size(); i++)
    if (d[v[i]]!=-1) w.pb(v[i]);
    sort(w.begin(),w.end());
    cout<<w.size()<<"\n";
    for (int i=0; i<w.size(); i++)
        cout<<w[i]<<" "<<d[w[i]]<<"\n";

}