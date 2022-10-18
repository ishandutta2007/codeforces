#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 2e6 + 11;

vector<int> pos[N];

string s,a,b;
int n,k;
bool use[N];
char res[N];


void up()
{
    cin>>k;
    cin>>s>>a>>b;
    n=s.size();
    s="."+s;
    a="."+a;
    b="."+b;
    for (int i=0; i<26; i++)
    {
        use[i]=0;
        res[i]='-';
        pos[i].clear();
    }
    for (int i=1; i<=n; i++)
    {
        pos[s[i]-'a'].pb(i);
    }
    string t=".";
    for (int i=1; i<=n; i++)
        t+="-";
    int ps=0,g=1;
    for (int i=1; i<=n; i++)
    {
        //cout<<i<<" - "<<t<<"\n";
        if (res[s[i]-'a']!='-')
        {
            t[i]=res[s[i]-'a'];
        }
        if (t[i]!='-')
    {
        if (t[i]<a[i]) {g=0;break;}
        if (t[i]>a[i]) {ps=i;g=0; break;}
    } else
    {
        for (int j=a[i]-'a'+1; j<k; j++)
            if (use[j]==0)
            {
                ps=i;
                break;
            }
        if (use[a[i]-'a']==1) {g=0; break;}
        res[s[i]-'a']=a[i];
        use[a[i]-'a']=1;
        t[i]=a[i];
    }
    }
    //cout<<"! "<<ps<<"\n";
    if (g==1)
    {
        cout<<"YES\n";
        for (int j=0; j<k; j++)
        {
            if (res[j]=='-')
            {
                for (int p=0; p<k; p++)
                    if (use[p]==0)
                {
                    use[p]=1;
                    res[j]=char(p+'a');
                    break;
                }
            }
            cout<<res[j];
        }
        cout<<"\n";
        return;
    }
    if (ps==0)
    {
        cout<<"NO\n";
        return;
    }
    for (int i=0; i<k; i++)
    {
        use[i]=0;
        res[i]='-';
    }
    for (int j=1; j<t.size(); j++)
        t[j]='-';
    for (int i=1; i<=n; i++)
    {
        //cout<<i<<" - "<<t<<" "<<s<<"\n";
        if (res[s[i]-'a']!='-') t[i]=res[s[i]-'a'];
        if (t[i]!='-')
        {} else
        if (i<ps)
        {
            use[a[i]-'a']=1;
            res[s[i]-'a']=a[i];
            t[i]=a[i];
        } else
        if (i==ps)
        {
            int tt=0;
            for (int j=a[i]-'a'+1; j<k; j++)
                if (use[j]==0) {tt=j; break;}
            res[s[i]-'a']=char(tt+'a');
            use[tt]=1;
            t[i]=char(tt+'a');
        } else
        {
            int tt=0;
            for (int j=0; j<k; j++)
                if (use[j]==0) {tt=j; break;}
            res[s[i]-'a']=char(tt+'a');
            use[tt]=1;
            t[i]=char(tt+'a');
        }
    }
    //cout<<"min string is "<<t<<endl;
    if (t>b)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";

    for (int j=0; j<k; j++)
        {
            if (res[j]=='-')
            {
                for (int p=0; p<k; p++)
                    if (use[p]==0)
                {
                    use[p]=1;
                    res[j]=char(p+'a');
                    break;
                }
            }
            cout<<res[j];
        }
    cout<<"\n";
}




int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        up();
    }
}