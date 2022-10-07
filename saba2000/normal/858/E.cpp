#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
vector<string> v[2];
int f[1000009];
vector<int> ocb,ocb1,fr,fr1;
vector<string> ras;
bool dig(string s)
{
    if(s[0]=='0') return 0;
    for (int i=0; i<s.size(); i++)
        if(s[i]<'0' || s[i]>'9') return 0;
    return 1;
}
int num(string s)
{int ans=0;
    for (int i=0; i<s.size(); i++)
        ans=ans*10+s[i]-'0';
    return ans;
}
string ans="";
void str(int k)
{
     ans="";
    while(k)
    {
        ans=(char)(k%10+'0')+ans;
        k/=10;
    }
    ras.push_back(ans);
}
void mov(int a, int b)
{
    printf("move ");
    printf("%d %d\n",a,b);
}
void mov1(string a, int b)
{
    printf("move ");
    for (int i=0; i<a.size(); i++)
        printf("%c",a[i]);
    printf(" %d\n",b);
}
void mov2(int a, string b)
{
    printf("move ");
    printf("%d ",a);
    for (int i=0; i<b.size(); i++)
        printf("%c",b[i]);
        printf("\n");
}
main()
{
    int n;
    int e=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string s;
        int t;
        cin>>s>>t;
        if(t) e++;
        if(dig(s)==0) {v[t].push_back(s); continue;}
      // cout<<num(s)<<endl;
        if(num(s)<=n && s!="0") {f[num(s)]=t+1;}

        else{f[num(s)]=5;v[t].push_back(s); continue;}
       // cout<<1<<endl;
    }

    for (int i=1; i<=e; i++)
       {
      //     cout<<f[i]<<endl;
        if(f[i]==1) ocb.push_back(i);
        else if(f[i]==0) fr.push_back(i);}
    for (int j=e+1; j<=n; j++)
        {//cout<<f[j]<<endl;
            if(f[j]==2) ocb1.push_back(j);
    else if(f[j]==0) fr1.push_back(j);}
    for(int i=n+1; i<=200000; i++)
        {if(f[i]!=5) str(i);
      //  if(i%1000==0) cout<<i<<endl;*/
        }
        if(fr.size()==0 && fr1.size()==0 && (ocb.size() || ocb1.size()))
            cout<<ocb.size()+ocb1.size()+v[0].size()+v[1].size()+1<<endl;
        else cout<<ocb.size()+ocb1.size()+v[0].size()+v[1].size()<<endl;

    while(1)
    {
       //cout<<fr.size()<<" "<<ocb.size()<<" "<<fr1.size()<<" "<<ocb1.size()<<" "<<v[0].size()<<" "<<v[1].size()<<endl;
        if(fr.size() && ocb1.size())
        {
            mov(ocb1[ocb1.size()-1],fr[fr.size()-1]);
            fr1.push_back(ocb1[ocb1.size()-1]);
            ocb1.pop_back(); fr.pop_back();
            continue;
        }
        if(fr1.size() && ocb.size())
        {
            mov(ocb[ocb.size()-1],fr1[fr1.size()-1]);
             fr.push_back(ocb[ocb.size()-1]);
             ocb.pop_back(); fr1.pop_back();
            continue;
        }
        if(v[0].size()==0 && v[1].size()==0 && ocb.size()==0 && ocb1.size()==0) break;
        if(fr.size() && v[1].size()) {
            mov1(v[1][v[1].size()-1],fr[fr.size()-1]);
            v[1].pop_back(); fr.pop_back();
            continue;
        }
         if(fr.size() && v[1].size()) {
            mov1(v[1][v[1].size()-1],fr[fr.size()-1]);
            v[1].pop_back(); fr.pop_back();
            continue;
        }
        if(fr1.size() && v[0].size()) {
               // cout<<fr1[fr.size()-1]<<endl;
            mov1(v[0][v[0].size()-1],fr1[fr1.size()-1]);
            v[0].pop_back(); fr1.pop_back();
            continue;
        }
        if(ocb.size()) {
            mov2(ocb[ocb.size()-1],ras[ras.size()-1]);
            v[0].push_back(ras[ras.size()-1]);
            fr.push_back(ocb[ocb.size()-1]);
            ras.pop_back(); ocb.pop_back();
            continue;
        }
         if(ocb1.size()) {
            mov2(ocb1[ocb1.size()-1],ras[ras.size()-1]);
            v[1].push_back(ras[ras.size()-1]);
             fr1.push_back(ocb1[ocb1.size()-1]);
            ras.pop_back(); ocb1.pop_back();
            continue;
        }
    }
}