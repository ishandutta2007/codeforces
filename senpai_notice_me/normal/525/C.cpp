//file: .cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,seg[100005],seg1=0,seg2;
long long ans;
bool comp(int a,int b)
{
    return a>b;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	    scanf("%d",&seg[i]);
	sort(seg+1,seg+n+1,comp);
	for(int i=1;i<n;i++)
	{
	    if(seg[i+1]==seg[i] || seg[i+1]==seg[i]-1)
	    {
	        if(!seg1)
	            seg1=seg[++i];
	        else
	        {
	            seg2=seg[++i];
	            ans+=1LL*seg1*seg2;
	            seg1=seg2=0;
	        }
	    }
    }
    cout<<ans;
	File_end:
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}