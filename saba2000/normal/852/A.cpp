#include<bits/stdc++.h>
using namespace std;
SS(int x)
{
    int S=0;
    while(x>0)
    {
      S+=x%10;
      x/=10;

    }
    return S;
}  int u;
main()
{

    srand(time(NULL));
   cin>>u;
    string n,N;
    cin>>n; N=n;
    strt:
        string anss="";
        n=N;
    int s=0;
    u=0;
    for (int i=0; i<n.size()-1; i++){
    {
        rand(); rand();
        u=u*10+n[i]-'0';
        anss+=n[i];
        if(rand()%2==1 || u>100000){
           s+=u; anss+="+"; u=0;
        }
    }
}
if(anss[(int)anss.size()-1]!='+' && anss.size()>0)anss+="+";
s+=u;
s+=n[n.size()-1]-'0';
anss+=n[n.size()-1];
string k="";
k="";
    while(s>0)
    {
        int x=s%10;
        s/=10;
        k=(char)(x+'0')+k;
    }
    n=k;
while(n.size()<8) n='0'+n;
int S=0;
int FL=0;
for (int i=0; i<(1<<7); i++)
{S=0;
    int u=0;
    for (int j=0; j<n.size(); j++)
    {
        u=u*10+n[j]-'0';
        if(i&(1<<j)) {S+=u;u=0;}
    }
    S+=u;
    if(SS(S)<10){
            cout<<anss<<endl;
int fl=0;FL=1;
        for (int j=0; j<n.size(); j++)
            {if(fl==1 || n[j]!='0'){fl=1; cout<<n[j];
        if(i&(1<<j)) cout<<"+";}}
        cout<<endl;
        break;
    }
}
if(FL==0) goto strt;
k="";
s=S;
    while(s>0)
    {
        int x=s%10;
        s/=10;
        k=(char)(x+'0')+k;
    }
    n=k;
    for (int i=0; i<n.size()-1; i++){
    s+=n[i]-'0';
    cout<<n[i]<<"+";
}
s+=n[n.size()-1]-'0';
cout<<n[n.size()-1]<<endl;
}