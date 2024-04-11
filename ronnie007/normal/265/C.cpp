#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;


string s;
int n;


int a[1000006];


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
	cin>>s;
	n=s.size();
    }


void solve()
    {
	int i;
	int left;
	int right;
	left=0;
	right=n-1;
	for(i=0;i<n;i++)
		{
		if(s[i]=='r')
			{
			a[left]=i+1;
			left++;
			}
		else
			{
			a[right]=i+1;
			right--;
			}
		}
	for(i=0;i<n;i++)
		{
		printf("%d\n",a[i]);
		}
    }