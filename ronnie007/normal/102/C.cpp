#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;


string a;
int n;
int k;
int used[50];
int used1[50];
void input();
void solve();


int main()
    {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input();
	solve();
    return 0;
    }


void input()
    {
	cin>>a;
	n=a.size();
	cin>>k;
    }


void solve()
	{
	int i,j;
	int br1=0;
	for(i=0;i<n;i++)
		{
		if(used[a[i]-'a']==0)br1++;
		used[a[i]-'a']++;
		}
	for(i=0;i<26;i++)
		{
		used1[i]=used[i];
		}
	sort(used,used+26);
	int sm=0;
	int br=0;
	for(i=0;i<26;i++)
		{
		sm+=used[i];
		if(sm>k){sm-=used[i];break;}
		if(used[i]!=0)br++;
		//used[i]=-1;
		}

	printf("%d\n",br1-br);
	int h=0;
	for(i=0;i<26;i++)
		{
		if(used[i]!=0)
			{
			if(h==br)break;
			h++;
			for(j=0;j<26;j++)
				{
				if(used[i]==used1[j]){used1[j]=-1;break;}
				}
			}
		}
	for(i=0;i<n;i++)
		{
		//cout<<used1[i]<<" ";
		}
	for(i=0;i<n;i++)
		{
		if(used1[a[i]-'a']!=-1)cout<<a[i];
		}
	cout<<"\n";
	}