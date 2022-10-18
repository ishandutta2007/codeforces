#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<string> res;

void rec(int cc, vector<string> vv)
{
    if (cc==0)
    {
        rec(1,vv);


        vector<string> ss;
        for (int i=0; i<vv.size(); i++)
        {
            string s="";
            for (int j=vv.size()-1; j>=0; j--)
                s+=vv[j][i];
            ss.pb(s);
        }
        rec(1,ss);


        ss.clear();
        for (int i=vv.size()-1; i>=0; i--)
        {
            string s="";
            for (int j=vv.size()-1; j>=0; j--)
                s+=vv[i][j];
            ss.pb(s);
        }
        rec(1,ss);

        ss.clear();
        for (int i=vv.size()-1; i>=0; i--)
        {
            string s="";
            for (int j=0; j<=vv.size()-1; j++)
                s+=vv[j][i];
            ss.pb(s);
        }
        rec(1,ss);

        return;
    }
    if (cc==1)
    {
        rec(2,vv);

        vector<string> ss;
        for (int i=0; i<vv.size(); i++)
        {
            string s="";
            for (int j=vv.size()-1; j>=0; j--)
                s+=vv[i][j];
            ss.pb(s);
        }
        rec(2,ss);
        return;
    }
    if (cc==2)
    {
        rec(3,vv);

        vector<string> ss;
        for (int j=vv.size()-1; j>=0; j--)
            ss.pb(vv[j]);
        rec(3,ss);
    }

    if (vv==res)
    {
        cout<<"Yes"<<endl;
        exit(0);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<string> vv;
    for (int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        vv.pb(s);
    }
    for (int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        res.pb(s);
    }
    rec(0,vv);
    cout<<"No"<<endl;
}