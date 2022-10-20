#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int br[50];
int used[50];
int findmax(string b);

int main()
    {
    string a;
    cin>>a;
    int i;
    int n=a.size();
    int k=0;
    int g;
    string h;
    h=a;
    int num;
    int last;
    
    while(k<=n-1)
        {
        num=findmax(h);
        //cout<<num<<"\n";
        for(i=k;i<n;i++)
            {
            if(a[i]==num+'a'){cout<<a[i];last=i;}
            }
        h.clear();
        for(i=last+1;i<n;i++)
            {
            h+=a[i];
            }
        k=last+1;
        }
    return 0;
    }
    
    
int findmax(string b)
    {
    int i;
    for(i=0;i<=26;i++)
        {
        br[i]=0;
        }
    for(i=0;i<b.size();i++)
        {
        br[(b[i]-'a')]++;
        }
    for(i=30;i>=0;i--)
        {
        if(br[i]!=0 && used[i]==0){used[i]=1;return i;}
        }
    }