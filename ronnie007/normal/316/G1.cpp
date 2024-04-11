#include<iostream>
#include<stdio.h>
#include<string>
#include<set>
using namespace std;

int main()
    {
    set<string>m;
    int ans[1000000];
    string s,s1,s2;
    cin>>s;
    for(int i=1;i<=s.size();i++)
        {
        for(int j=0;j<s.size()-i+1;j++)
            {
            s1=s.substr(j,i);
            m.insert(s1);
            }
        }
    int n,k,k1,p,z,br,ans1=0,l;
    cin>>n;
    if(n==0)
        {
        cout<<m.size()<<"\n";
        return 0;
        }
    for(int i=0;i<n;i++)
        {
        z=0;
        cin>>s1;
        cin>>k>>k1;
        for(set <string>::iterator it=m.begin();it!=m.end();it++)
            {
            br=1;
            s2=*it;
            p=0;
            l=s1.find(s2,0);

            p=l+1;
            while(l!=string::npos)
                {

                l=s1.find(s2,p);
                p=l+1;
                br++;
                if(br>k1+1)break;
                }

            br--;
            if(br>=k && br<=k1)
                {
                ans[z]++;
                if(i+1==n && ans[z]==n){ans1++;}
                }
            z++;
            }
        }
    cout<<ans1<<"\n";
    return 0;
    }