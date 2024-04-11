#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;


string s,ans;
int kol;

char g[N];

int dist(string a, string b)
{
    int koll=0;
    for (int t=0; t<a.size(); t++)
        if (a[t]!=b[t]) koll++;
    return koll;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    s=".";
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        char ch;
        cin>>ch;
        s+=ch;
    }
    kol=2e9;

    g[1]='A';
    g[2]='C';
    g[3]='T';
    g[4]='G';
    for (int l=1; l<=4; l++)
    for (int r=1; r<=4; r++)
    for (int p=1; p<=4; p++)
    for (int k=1; k<=4; k++)
    if (l!=r&&l!=p&&l!=k&&r!=p&&r!=k&&p!=k)
    {
        char ch1=g[l],ch2=g[r],ch3=g[p],ch4=g[k];
        int get=0;
        int t=0;
        string res=".";
        for (int i=1; i<=n; i++)
        {
            string b="",c="",a="";
            for (int j=1; j<=m; j++)
            {
                t++;
                a+=s[t];
            }
            for (int j=1; j<=m; j++)
                if (i%2==1&&j%2==1) {b+=ch1; c+=ch2;} else
                if (i%2==1) {b+=ch2; c+=ch1;} else
                if (j%2==1) {b+=ch3; c+=ch4;} else {b+=ch4; c+=ch3;}
            int p1=dist(a,b),p2=dist(a,c);
            if (p1<p2)
            {
                get+=p1;
                res+=b;
            } else
            {
                get+=p2;
                res+=c;
            }
        }
        if (get<kol)
        {
            kol=get;
            ans=res;
        }
        get=0;
        for (int j=1; j<=m; j++)
        {
            string b="",c="",a="";
            for (int i=1; i<=n; i++)
            {
                a+=s[(i-1)*m+j];
            }
            for (int i=1; i<=n; i++)
                if (j%2==1&&i%2==1) {b+=ch1; c+=ch2;} else
                if (j%2==1) {b+=ch2; c+=ch1;} else
                if (i%2==1) {b+=ch3; c+=ch4;} else {b+=ch4; c+=ch3;}
            int p1=dist(a,b),p2=dist(a,c);
            if (p1<p2)
            {
                get+=p1;
                for (int i=1; i<=n; i++)
                    res[(i-1)*m+j]=b[i-1];
            } else
            {
                get+=p2;
                for (int i=1; i<=n; i++)
                    res[(i-1)*m+j]=c[i-1];
            }
        }
        if (get<kol)
        {
            kol=get;
            ans=res;
        }
    }
    //cout<<kol<<endl;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            cout<<ans[(i-1)*m+j];
        cout<<"\n";
    }
}